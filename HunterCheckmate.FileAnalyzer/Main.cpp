#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include "AdfFile.h"

// TODO: - add -rep -preset presets
// TODO: - add preset cli (print available presets upon asking user which animal presets to print)
// TODO: - add -rep -custom type converter to std::vector<char>*
// TODO: - implement ReplaceAnimal overload for AnimalData objects (=> add std::vector<char>* into AnimalData)
// 
// TODO: - make exception class for e.g. if (!initialized) return 0 in AdfFile.cpp;
// TODO: - change Utility class to accept input file destination and handle setting up if's and of's on its own
// TODO: - refactor, faster runtime

void PrintUsage()
{
	std::cout << "Usage: HunterCheckmate.FileAnalyzer.exe <population_file_path> [-oc | -of | -ocg | -rep <[-custom | -preset]>" << std::endl
		<< std::setw(6) << "-oc: " << std::setw(0) << "Output whole file contents on console" << std::endl
		<< std::setw(6) << "-of: " << std::setw(0) << "Output whole file contents into .txt file" << std::endl
		<< std::setw(6) << "-ocg: " << std::setw(0) << "Output animal group informations on console" << std::endl
		<< std::setw(6) << "-rep: " << std::setw(0) << "Replaces an animal with a new one" << std::endl
		<< "     " << std::setw(9) << "-custom: " << std::setw(0) << "Specify animal data yourself" << std::endl
		<< "     " << std::setw(9) << "-preset: " << std::setw(0) << "Choose from some of the presets" << std::endl;
}

bool ContainsElement(char *arr[], const std::string &element)
{
	uint8_t idx = 0;
	while (arr[idx] != nullptr)
	{
		if (std::string(arr[idx]) == element) return true;
		idx++;
	}
	return false;
}

uint8_t GetPosition(char *arr[], const std::string &element)
{
	uint8_t idx = 0;
	uint8_t pos = idx;
	while (arr[idx] != nullptr)
	{
		if (std::string(arr[idx]) == element) pos = idx;
		idx++;
	}
	return pos;
}

void SetMask(char *arr[], std::vector<bool> *mask, uint8_t pos, std::vector<std::string> *values)
{
	uint32_t idx = pos;
	while (arr[idx] != nullptr)
	{
		idx++;
		if (arr[idx] == nullptr) break;
		
		auto it = std::find(values->begin(), values->end(), std::string(arr[idx]));
		if (it == values->end()) break;
		
		const uint32_t it_pos = it - values->begin();
		mask->at(it_pos) = true;
	}

	// Set everything to true, since user wants to get info of everything
	auto it = std::find(mask->begin(), mask->end(), true);
	if (it == mask->end()) std::replace(mask->begin(), mask->end(), false, true);
}

void SetMask(char *arr[], std::vector<bool> *mask, uint8_t pos)
{
	uint32_t idx = pos;
	while (arr[idx] != nullptr)
	{
		idx++;
		if (arr[idx] == nullptr) break;
		if (std::string(arr[idx]) == "-custom") { mask->at(0) = true; break; }
		if (std::string(arr[idx]) == "-preset") { mask->at(1) = true; break; }
	}
}

int main(int argc, char *argv[])
{
	using namespace HunterCheckmate_FileAnalyzer;

	const char* file_path;
	bool flag_oc, flag_of, flag_ocg, flag_rep = false;
	
	uint8_t mask_ocg_pos;
	std::vector<bool> mask_ocg = std::vector<bool>(8);
	auto *mask_ocg_values = new std::vector<std::string>();

	uint8_t mask_rep_pos;
	std::vector<bool> mask_rep = std::vector<bool>(2);
	
	if (argc < 2) {	PrintUsage(); return 1;	}
	if (argc == 2 && ContainsElement(argv,  "-h")) { PrintUsage(); return 1; }
	if (argc >= 2) { file_path = argv[1]; }
	else { return 1; }
	if (argc >= 3)
	{
		flag_oc = ContainsElement(argv, "-oc");
		flag_of = ContainsElement(argv, "-of");
		flag_ocg = ContainsElement(argv, "-ocg");
		if (flag_ocg)
		{
			mask_ocg_pos = GetPosition(argv, "-ocg");
			*mask_ocg_values = {"-moose", "-jackrabbit", "-mallard", "-blackbear", "-elk", "-coyote", "-blacktail", "-whitetail"};
			SetMask(argv, &mask_ocg, mask_ocg_pos, mask_ocg_values);
		}
		flag_rep = ContainsElement(argv, "-rep");
		if (flag_rep)
		{
			mask_rep_pos = GetPosition(argv, "-rep");
			SetMask(argv, &mask_rep, mask_rep_pos);
			if (std::find(mask_rep.begin(), mask_rep.end(), true) == mask_rep.end()) { PrintUsage(); return 1; }
		}
	}
	
	auto *ifstream = new std::ifstream(file_path, std::ios::binary | std::ios::out | std::ios::in | std::ios::ate);
	auto *ofstream = new std::ofstream(file_path, std::ios::binary | std::ios::out | std::ios::in | std::ios::ate);

	if (!(ifstream->is_open() && ofstream->is_open())) return 1;

	auto *utility = new Utility(Endian::Little, ifstream, ofstream);
	auto* adf = new AdfFile(utility);
	bool success = adf->Deserialize();
	
	// console output
	if (success && flag_oc)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "GENERAL HEADER INFO:" << std::endl;
		std::cout << "Version:			" << std::dec << adf->header->version << std::endl;
		std::cout << "Instance_count:			" << std::dec << adf->header->instance_count << std::endl;
		std::cout << "Instance_offset:		0x" << std::hex << adf->header->instance_offset << std::endl;
		std::cout << "Typedef_count:			" << std::dec << adf->header->typedef_count << std::endl;
		std::cout << "Typedef_offset:			0x" << std::hex << adf->header->typedef_offset << std::endl;
		std::cout << "Strhash_count:			" << std::dec << adf->header->strhash_count << std::endl;
		std::cout << "Strhash_offset:			0x" << std::hex << adf->header->strhash_offset << std::endl;
		std::cout << "Nametable_count:		" << std::dec << adf->header->nametable_count << std::endl;
		std::cout << "Nametable_offset:		0x" << std::hex << adf->header->nametable_offset << std::endl;
		std::cout << "Total_size:			" << std::dec << adf->header->total_size << std::endl;
		std::cout << "Comment:			" << adf->header->comment << std::endl;
		std::cout << "====================================================" << std::endl << std::endl;
		
		uint32_t i = 0;
		for (auto it = adf->header_instances->begin(); it != adf->header_instances->end(); ++it)
		{
			std::cout << "====================================================" << std::endl;
			std::cout << "INSTANCE HEADER NUMBER: " << std::dec << i << std::endl;
			std::cout << "Name_hash:			0x" << std::hex << it->name_hash << std::endl;
			std::cout << "Type_hash:			0x" << std::hex << it->type_hash << std::endl;
			std::cout << "Offset:				0x" << std::hex << it->offset << std::endl;
			std::cout << "Size:				0x" << std::hex << it->size << std::endl;
			std::cout << "Name_idx			" << std::dec << it->name_idx << std::endl;
			std::cout << "====================================================" << std::endl << std::endl;
			i++;
		}

		i = 0;
		for (auto it = adf->header_typedef->begin(); it != adf->header_typedef->end(); ++it)
		{
			std::cout << "====================================================" << std::endl;
			std::cout << "TYPEDEF HEADER NUMBER: " << std::dec << i << std::endl;
			std::cout << "Type:				" << std::hex << typeString[static_cast<uint32_t>(it->type)] << std::endl;
			std::cout << "Size:				0x" << std::hex << it->size << std::endl;
			std::cout << "Alignment:			0x" << std::hex << it->alignment << std::endl;
			std::cout << "Name_hash:			0x" << std::hex << it->name_hash << std::endl;
			std::cout << "Name_idx:			0x" << std::hex << it->name_idx << std::endl;
			std::cout << "Name:				0x" << std::hex << it->name << std::endl;
			std::cout << "Flags:				0x" << std::hex << it->flags << std::endl;
			std::cout << "Element_type_hash:		0x" << std::hex << it->element_type_hash << std::endl;
			std::cout << "Element_length:			0x" << std::hex << it->element_length << std::endl;
			std::cout << "Member count:			0x" << std::dec << it->member_count << std::endl;
			if (it->type == Type::Structure)
			{
				uint32_t j = 0;
				for (auto mem_it = it->member_headers.begin(); mem_it != it->member_headers.end(); ++mem_it)
				{
					std::cout << "\nMEMBER HEADER NUMBER: " << std::dec << j << std::endl;
					std::cout << "Name_idx:			0x" << std::hex << mem_it->name_idx << std::endl;
					std::cout << "Type_hash:			0x" << std::hex << mem_it->type_hash << std::endl;
					std::cout << "Size:				0x" << std::hex << mem_it->size << std::endl;
					std::cout << "Offset:				0x" << std::hex << mem_it->offset << std::endl;
					std::cout << "Default_type:			0x" << std::hex << mem_it->default_type << std::endl;
					std::cout << "Default_value:			0x" << std::hex << mem_it->default_value << std::endl;
					j++;
				}
			}
			std::cout << "====================================================" << std::endl << std::endl;
			i++;
		}

		std::cout << "====================================================";
		for (i = 0; i < adf->header_nametable->size->size(); i++)
		{	
			std::cout << "\nNAME NUMBER: " << std::dec << i << std::endl;
			std::cout << "Name: " << std::hex << adf->header_nametable->name->at(i).c_str() << std::endl;
			std::cout << "Size: " << std::dec << static_cast<int>(adf->header_nametable->size->at(i)) << std::endl;
		}
		std::cout << "====================================================" << std::endl << std::endl;

		i = 0;
		for (auto it = adf->instances->begin(); it != adf->instances->end(); ++it)
		{
			std::cout << "====================================================";
			std::cout << "\nINSTANCE NUMBER: " << std::dec << i << std::endl;
			auto j = 0;
			if (it->members == nullptr || it->members->empty()) continue;
			for (auto jt = it->members->begin(); jt != it->members->end(); ++jt)
			{
				std::cout << "	MEMBER NUMBER: " << std::dec << j << std::endl;
				std::cout << "	Type: " << typeString[static_cast<uint32_t>(jt->type)] << ", PrimitiveType: " << primitiveString(jt->primitive) << ", Offset: 0x" << std::hex << jt
					->offset << ", Size: 0x" << std::hex << jt->size << std::endl;

				if (jt->data != nullptr && jt->primitive != Primitive::NONE)
				{
					std::cout << "	Raw_Data: " << std::hex << jt->data << std::endl;
					std::cout << "	Data: ";
					switch (jt->primitive)
					{
					case (Primitive::UINT8_T):
						{
						uint8_t data;
						memcpy(&data, jt->data, 1);
						std::cout << std::dec << static_cast<unsigned short>(data);
						break;
						}
					case (Primitive::UINT32_T):
						{
						uint32_t data;
						memcpy(&data, jt->data, 4);
						std::cout << std::dec << static_cast<unsigned long>(data);
						break;
						}
					case (Primitive::UINT64_T):
						{
						uint64_t data;
						memcpy(&data, jt->data, 8);
						std::cout << std::dec << static_cast<unsigned long long>(data);
						break;
						}
					case (Primitive::SINT32_T):
						{
						int32_t data;
						memcpy(&data, jt->data, 4);
						std::cout << std::dec << static_cast<long>(data);
						break;
						}
					case (Primitive::FLOAT):
						{
						float data;
						memcpy(&data, jt->data, 4);
						std::cout << std::dec << static_cast<float>(data);
						break;
						}
					default:
						break;
						
					}
					std::cout << std::endl;
				}

				auto k = 0;
				if (jt->sub_members == nullptr || jt->sub_members->empty()) continue;
				for (auto kt = jt->sub_members->begin(); kt != jt->sub_members->end(); ++kt)
				{
					std::cout << "		SUB_MEMBER NUMBER: " << std::dec << k << std::endl;
					std::cout << "		Type: " << typeString[static_cast<uint32_t>(kt->type)] << ", PrimitiveType: " << primitiveString(kt->primitive) << ", Offset: 0x" << std::hex << kt
						->offset << ", Size: 0x" << std::hex << kt->size << std::endl;

					if (kt->data != nullptr && kt->primitive != Primitive::NONE)
					{
						std::cout << "		Raw_Data: " << kt->data << std::endl;
						std::cout << "		Data: ";
						switch (kt->primitive)
						{
						case (Primitive::UINT8_T):
						{
							uint8_t data;
							memcpy(&data, kt->data, 1);
							std::cout << std::dec << static_cast<unsigned short>(data);;
							break;
						}
						case (Primitive::UINT32_T):
						{
							uint32_t data;
							memcpy(&data, kt->data, 4);
							std::cout << std::dec << static_cast<unsigned long>(data);
							break;
						}
						case (Primitive::UINT64_T):
						{
							uint64_t data;
							memcpy(&data, kt->data, 8);
							std::cout << std::dec << static_cast<unsigned long long>(data);
							break;
						}
						case (Primitive::SINT32_T):
						{
							int32_t data;
							memcpy(&data, kt->data, 4);
							std::cout << std::dec << static_cast<long>(data);
							break;
						}
						case (Primitive::FLOAT):
						{
							float data;
							memcpy(&data, kt->data, 4);
							std::cout << std::dec << static_cast<float>(data);
							break;
						}
						default:
							break;

						}
						std::cout << std::endl;
					}

					auto l = 0;
					if (kt->sub_members == nullptr || kt->sub_members->empty()) continue;
					for (auto lt = kt->sub_members->begin(); lt != kt->sub_members->end(); ++lt)
					{
						std::cout << "			SUB_SUB_MEMBER NUMBER: " << std::dec << l << std::endl;
						std::cout << "			Type: " << typeString[static_cast<uint32_t>(lt->type)] << ", PrimitiveType: " << primitiveString(lt->primitive) << ", Offset: 0x" << std::hex << lt
							->offset << ", Size: 0x" << std::hex << lt->size << std::endl;

						if (lt->data != nullptr && lt->primitive != Primitive::NONE)
						{
							std::cout << "			Raw_Data: " << lt->data << std::endl;
							std::cout << "			Data: ";
							switch (lt->primitive)
							{
							case (Primitive::UINT8_T):
							{
								uint8_t data;
								memcpy(&data, lt->data, 1);
								std::cout << std::dec << static_cast<unsigned short>(data);;
								break;
							}
							case (Primitive::UINT32_T):
							{
								uint32_t data;
								memcpy(&data, lt->data, 4);
								std::cout << std::dec << static_cast<unsigned long>(data);
								break;
							}
							case (Primitive::UINT64_T):
							{
								uint64_t data;
								memcpy(&data, lt->data, 8);
								std::cout << std::dec << static_cast<unsigned long long>(data);
								break;
							}
							case (Primitive::SINT32_T):
							{
								int32_t data;
								memcpy(&data, lt->data, 4);
								std::cout << std::dec << static_cast<long>(data);
								break;
							}
							case (Primitive::FLOAT):
							{
								float data;
								memcpy(&data, lt->data, 4);
								std::cout << std::dec << static_cast<float>(data);
								break;
							}
							default:
								break;

							}
							std::cout << std::endl;
						}

						auto m = 0;
						if (lt->sub_members == nullptr || lt->sub_members->empty()) continue;
						for (auto mt = lt->sub_members->begin(); mt != lt->sub_members->end(); ++mt)
						{
							std::cout << "				SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << m << std::endl;
							std::cout << "				Type: " << typeString[static_cast<uint32_t>(mt->type)] << ", PrimitiveType: " << primitiveString(mt->primitive) << ", Offset: 0x" << std::hex << mt
								->offset << ", Size: 0x" << std::hex << mt->size << std::endl;

							if (mt->data != nullptr && mt->primitive != Primitive::NONE)
							{
								std::cout << "				Raw_Data: " << mt->data << std::endl;
								std::cout << "				Data: ";
								switch (mt->primitive)
								{
								case (Primitive::UINT8_T):
								{
									uint8_t data;
									memcpy(&data, mt->data, 1);
									std::cout << std::dec << static_cast<unsigned short>(data);
									break;
								}
								case (Primitive::UINT32_T):
								{
									uint32_t data;
									memcpy(&data, mt->data, 4);
									std::cout << std::dec << static_cast<unsigned long>(data);
									break;
								}
								case (Primitive::UINT64_T):
								{
									uint64_t data;
									memcpy(&data, mt->data, 8);
									std::cout << std::dec << static_cast<unsigned long long>(data);
									break;
								}
								case (Primitive::SINT32_T):
								{
									int32_t data;
									memcpy(&data, mt->data, 4);
									std::cout << std::dec << static_cast<long>(data);
									break;
								}
								case (Primitive::FLOAT):
								{
									float data;
									memcpy(&data, mt->data, 4);
									std::cout << std::dec << static_cast<float>(data);
									break;
								}
								default:
									break;

								}
								std::cout << std::endl;
							}

							auto n = 0;
							if (mt->sub_members == nullptr || mt->sub_members->empty()) continue;
							for (auto nt = mt->sub_members->begin(); nt != mt->sub_members->end(); ++nt)
							{
								std::cout << "					SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << n << std::endl;
								std::cout << "					Type: " << typeString[static_cast<uint32_t>(nt->type)] << ", PrimitiveType: " << primitiveString(nt->primitive) << ", Offset: 0x" << std::hex << nt
									->offset << ", Size: 0x" << std::hex << nt->size << std::endl;

								if (nt->data != nullptr && nt->primitive != Primitive::NONE)
								{
									std::cout << "					Raw_Data: " << nt->data << std::endl;
									std::cout << "					Data: ";
									switch (nt->primitive)
									{
									case (Primitive::UINT8_T):
									{
										uint8_t data;
										memcpy(&data, nt->data, 1);
										std::cout << std::dec << static_cast<unsigned short>(data);
										break;
									}
									case (Primitive::UINT32_T):
									{
										uint32_t data;
										memcpy(&data, nt->data, 4);
										std::cout << std::dec << static_cast<unsigned long>(data);
										break;
									}
									case (Primitive::UINT64_T):
									{
										uint64_t data;
										memcpy(&data, nt->data, 8);
										std::cout << std::dec << static_cast<unsigned long long>(data);
										break;
									}
									case (Primitive::SINT32_T):
									{
										int32_t data;
										memcpy(&data, nt->data, 4);
										std::cout << std::dec << static_cast<long>(data);
										break;
									}
									case (Primitive::FLOAT):
									{
										float data;
										memcpy(&data, nt->data, 4);
										std::cout << std::dec << static_cast<float>(data);
										break;
									}
									default:
										break;

									}
									std::cout << std::endl;
								}

								auto o = 0;
								if (nt->sub_members == nullptr || nt->sub_members->empty()) continue;
								for (auto ot = nt->sub_members->begin(); ot != nt->sub_members->end(); ++ot)
								{
									std::cout << "						SUB_SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << o << std::endl;
									std::cout << "						Type: " << typeString[static_cast<uint32_t>(ot->type)] << ", PrimitiveType: " << primitiveString(ot->primitive) << ", Offset: 0x" << std::hex << ot
										->offset << ", Size: 0x" << std::hex << ot->size << std::endl;

									if (ot->data != nullptr && ot->primitive != Primitive::NONE)
									{
										std::cout << "						Raw_Data: " << ot->data << std::endl;
										std::cout << "						Data: ";
										switch (ot->primitive)
										{
										case (Primitive::UINT8_T):
										{
											uint8_t data;
											memcpy(&data, ot->data, 1);
											std::cout << std::dec << static_cast<unsigned short>(data);
											break;
										}
										case (Primitive::UINT32_T):
										{
											uint32_t data;
											memcpy(&data, ot->data, 4);
											std::cout << std::dec << static_cast<unsigned long>(data);
											break;
										}
										case (Primitive::UINT64_T):
										{
											uint64_t data;
											memcpy(&data, ot->data, 8);
											std::cout << std::dec << static_cast<unsigned long long>(data);
											break;
										}
										case (Primitive::SINT32_T):
										{
											int32_t data;
											memcpy(&data, ot->data, 4);
											std::cout << std::dec << static_cast<long>(data);
											break;
										}
										case (Primitive::FLOAT):
										{
											float data;
											memcpy(&data, ot->data, 4);
											std::cout << std::dec << static_cast<float>(data);
											break;
										}
										default:
											break;

										}
										std::cout << std::endl;
									}

									auto p = 0;
									if (ot->sub_members == nullptr || ot->sub_members->empty()) continue;
									for (auto pt = ot->sub_members->begin(); pt != ot->sub_members->end(); ++pt)
									{
										std::cout << "						SUB_SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << p << std::endl;
										std::cout << "						Type: " << typeString[static_cast<uint32_t>(pt->type)] << ", PrimitiveType: " << primitiveString(pt->primitive) << ", Offset: 0x" << std::hex << pt
											->offset << ", Size: 0x" << std::hex << pt->size << std::endl;

										if (pt->data != nullptr && pt->primitive != Primitive::NONE)
										{
											std::cout << "						Raw_Data: " << pt->data << std::endl;
											std::cout << "						Data: ";
											switch (pt->primitive)
											{
											case (Primitive::UINT8_T):
											{
												uint8_t data;
												memcpy(&data, pt->data, 1);
												std::cout << std::dec << static_cast<unsigned short>(data);
												break;
											}
											case (Primitive::UINT32_T):
											{
												uint32_t data;
												memcpy(&data, pt->data, 4);
												std::cout << std::dec << static_cast<unsigned long>(data);
												break;
											}
											case (Primitive::UINT64_T):
											{
												uint64_t data;
												memcpy(&data, pt->data, 8);
												std::cout << std::dec << static_cast<unsigned long long>(data);
												break;
											}
											case (Primitive::SINT32_T):
											{
												int32_t data;
												memcpy(&data, pt->data, 4);
												std::cout << std::dec << static_cast<long>(data);
												break;
											}
											case (Primitive::FLOAT):
											{
												float data;
												memcpy(&data, pt->data, 4);
												std::cout << std::dec << static_cast<float>(data);
												break;
											}
											default:
												break;

											}
											std::cout << std::endl;
										}

										auto q = 0;
										if (pt->sub_members == nullptr || pt->sub_members->empty()) continue;
										for (auto qt = pt->sub_members->begin(); qt != pt->sub_members->end(); ++qt)
										{
											std::cout << "						SUB_SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << p << std::endl;
											std::cout << "						Type: " << typeString[static_cast<uint32_t>(qt->type)] << ", PrimitiveType: " << primitiveString(qt->primitive) << ", Offset: 0x" << std::hex << qt
												->offset << ", Size: 0x" << std::hex << qt->size << std::endl;

											if (qt->data != nullptr && qt->primitive != Primitive::NONE)
											{
												std::cout << "						Raw_Data: " << qt->data << std::endl;
												std::cout << "						Data: ";
												switch (qt->primitive)
												{
												case (Primitive::UINT8_T):
												{
													uint8_t data;
													memcpy(&data, qt->data, 1);
													std::cout << std::dec << static_cast<unsigned short>(data);
													break;
												}
												case (Primitive::UINT32_T):
												{
													uint32_t data;
													memcpy(&data, qt->data, 4);
													std::cout << std::dec << static_cast<unsigned long>(data);
													break;
												}
												case (Primitive::UINT64_T):
												{
													uint64_t data;
													memcpy(&data, qt->data, 8);
													std::cout << std::dec << static_cast<unsigned long long>(data);
													break;
												}
												case (Primitive::SINT32_T):
												{
													int32_t data;
													memcpy(&data, qt->data, 4);
													std::cout << std::dec << static_cast<long>(data);
													break;
												}
												case (Primitive::FLOAT):
												{
													float data;
													memcpy(&data, qt->data, 4);
													std::cout << std::dec << static_cast<float>(data);
													break;
												}
												default:
													break;

												}
												std::cout << std::endl;
											}



											q++;
										}

										p++;
									}

									o++;
								}

								n++;
							}

							m++;
						}

						l++;
					}
					
					k++;
				}

				j++;
			}
			i++;
		}
	}

	// file output
	if (success && flag_of)
	{
		std::ofstream *output_file = new std::ofstream;
		output_file->open(R"(C:\Users\oleSQL\Documents\thehunter working\pop\animal_population_1_info.txt)", std::ios::out | std::ios::ate | std::ios::trunc);

		*output_file << "**************************************** HEADER INFO GENERAL ****************************************" << std::endl
		<< "*" << std::setw(100) << std::right << "*" << std::endl << std::right
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Version: " << std::setw(32) << std::left << std::dec << adf->header->version << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Instance_count: " << std::setw(32) << std::left << std::dec << adf->header->instance_count << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Instance_offset: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << adf->header->instance_offset << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Typedef_count: " << std::setw(32) << std::left << std::dec << adf->header->typedef_count << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Typedef_offset: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << adf->header->typedef_offset << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Strhash_count: " << std::setw(32) << std::left << std::dec << adf->header->strhash_count << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Strhash_offset: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << adf->header->strhash_offset << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Nametable_count: " << std::setw(32) << std::left << std::dec << adf->header->nametable_count << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Nametable_offset: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << adf->header->nametable_offset << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Total_size: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << adf->header->total_size << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Comment: " << std::setw(32) << std::left << adf->header->comment << std::setw(43) << std::right << "*" << std::endl
		<< "*" << std::setw(100) << std::right << "*" << std::endl
		<< "*****************************************************************************************************" << std::endl << std::endl;

		for (auto it = adf->header_instances->begin(); it != adf->header_instances->end(); ++it)
		{
			uint32_t idx = it - adf->header_instances->begin();
			*output_file << "************************************** HEADER INFO INSTANCE " << std::dec << idx << " ***************************************" << std::endl
			<< "*" << std::setw(100) << std::right << "*" << std::endl << std::right
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Name: " << std::left << std::setw(32) << std::hex << adf->header_nametable->name->at(1).c_str() << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Name_hash: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->name_hash << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Type_hash: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->type_hash << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Offset: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->offset << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Size: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->size << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Name_idx: " << std::setw(32) << std::left << std::dec << it->name_idx << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(100) << std::right << "*" << std::endl
			<< "*****************************************************************************************************" << std::endl << std::endl;
		}

		for (auto it = adf->header_typedef->begin(); it != adf->header_typedef->end(); ++it)
		{
			uint32_t idx = it - adf->header_typedef->begin();
			const char* tmp;
			if (idx >= 10) tmp = " ***************************************";
			else tmp = " ****************************************";

			*output_file << "************************************** HEADER INFO TYPEDEF " << std::dec << idx << tmp << std::endl
			<< "*" << std::setw(100) << std::right << "*" << std::endl << std::right
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Name: " << std::left << std::setw(32) << std::hex << adf->header_nametable->name->at(static_cast<const unsigned int>(it->name_idx)).c_str() << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Type: " << std::setw(32) << std::left << std::dec << typeString[static_cast<uint32_t>(it->type)] << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Size: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->size << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Alignment: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->alignment << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Name_hash: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->name_hash << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Name_idx: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->name_idx << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Name: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->name << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Flags: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->flags << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Element_type_hash: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->element_type_hash << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Element_length: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << it->element_length << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(0) << "     " << std::setw(20) << std::right << "Member count: " << std::setw(32) << std::left << std::dec << it->member_count << std::setw(43) << std::right << "*" << std::endl
			<< "*" << std::setw(100) << std::right << "*" << std::endl;
			if (it->type == Type::Structure)
			{
				for (auto mem_it = it->member_headers.begin(); mem_it != it->member_headers.end(); ++mem_it)
				{
					uint32_t mem_idx = mem_it - it->member_headers.begin();
					if (mem_idx >= 10) tmp = " *********************************";
					else tmp = " **********************************";
					
					*output_file << "*" << std::setw(0) << "     " << "********************************* HEADER INFO MEMBER " << std::dec << mem_idx << tmp << "     " << "*" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(89) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Name: " << std::left << std::setw(32) << std::hex << adf->header_nametable->name->at(static_cast<const unsigned int>(mem_it->name_idx)).c_str() << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Type: " << std::left << std::setw(32) << std::hex << primitiveString(Primitive(mem_it->type_hash)) << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Name_idx: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << mem_it->name_idx << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Type_hash: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << mem_it->type_hash << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Size: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << mem_it->size << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Offset: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << mem_it->offset << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Default_type: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << mem_it->default_type << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Default_value: " << std::setw(2) << std::left << "0x" << std::setw(30) << std::hex << mem_it->default_value << std::setw(42) << std::right << "*     *" << std::endl
					<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(89) << std::right << "*     *" << std::endl;
				}
			}

			*output_file << "*     *****************************************************************************************     *" << std::endl
			<< "*" << std::setw(100) << std::right << "*" << std::endl << std::right
			<< "*****************************************************************************************************" << std::endl << std::endl;
		}

		*output_file << "***************************************** HEADER NAMETABLE ******************************************" << std::endl
		<< "*" << std::setw(100) << std::right << "*" << std::endl << std::right;
		for (uint32_t i = 0; i < adf->header_nametable->size->size(); i++)
		{
			const char* tmp;
			if (i >= 10) tmp = " ***************************************";
			else tmp = " ****************************************";

			*output_file << "*" << std::setw(0) << "     " << "***************************************** NAME " << std::dec << i << tmp << "     " << "*" << std::endl
			<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(89) << std::right << "*     *" << std::endl
			<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Name: " << std::setw(32) << std::left << std::hex << adf->header_nametable->name->at(i).c_str() << std::setw(42) << std::right << "*     *" << std::endl
			<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(15) << std::right << "Size: " << std::setw(32) << std::left << std::dec << static_cast<int>(adf->header_nametable->size->at(i)) << std::setw(42) << std::right << "*     *" << std::endl
			<< "*" << std::setw(0) << "     " << "*" << std::setw(0) << "     " << std::setw(89) << std::right << "*     *" << std::endl;
		}
		*output_file << "*     *****************************************************************************************     *" << std::endl
		<< "*" << std::setw(100) << std::right << "*" << std::endl << std::right
		<< "*****************************************************************************************************" << std::endl << std::endl;

		for (auto it = adf->instances->begin(); it != adf->instances->end(); ++it)
		{
			uint32_t idx_0 = it - adf->instances->begin();
			const char* tmp;
			if (idx_0 >= 10) tmp = " ***************************************";
			else tmp = " ****************************************";

			*output_file << "******************************************* INSTANCE " << std::dec << idx_0 << tmp << std::endl
			<< "*" << std::setw(100) << std::right << "*" << std::endl << std::right;
			
			if (it->members == nullptr || it->members->empty()) continue;
			for (auto jt = it->members->begin(); jt != it->members->end(); ++jt)
			{
				uint32_t idx_1 = jt - it->members->begin();
				*output_file << "     MEMBER " << std::dec << idx_1 << std::endl
				<< "          Type: " << typeString[static_cast<uint32_t>(jt->type)] << ", PrimitiveType: " << primitiveString(jt->primitive) << ", Offset: 0x" << std::hex << jt->offset << ", Size: 0x" << std::hex << jt->size << std::endl;

				if (jt->data != nullptr && jt->primitive != Primitive::NONE)
				{
					*output_file << "          Data: ";
					switch (jt->primitive)
					{
					case (Primitive::UINT8_T):
					{
						uint8_t data;
						memcpy(&data, jt->data, 1);
						*output_file << std::dec << static_cast<unsigned short>(data);
						break;
					}
					case (Primitive::UINT32_T):
					{
						uint32_t data;
						memcpy(&data, jt->data, 4);
						*output_file << std::dec << static_cast<unsigned long>(data);
						break;
					}
					case (Primitive::UINT64_T):
					{
						uint64_t data;
						memcpy(&data, jt->data, 8);
						*output_file << std::dec << static_cast<unsigned long long>(data);
						break;
					}
					case (Primitive::SINT32_T):
					{
						int32_t data;
						memcpy(&data, jt->data, 4);
						*output_file << std::dec << static_cast<long>(data);
						break;
					}
					case (Primitive::FLOAT):
					{
						float data;
						memcpy(&data, jt->data, 4);
						*output_file << std::dec << static_cast<float>(data);
						break;
					}
					default:
						break;

					}
					*output_file << std::endl;
				}

				if (jt->sub_members == nullptr || jt->sub_members->empty()) continue;
				for (auto kt = jt->sub_members->begin(); kt != jt->sub_members->end(); ++kt)
				{
					uint32_t idx_2 = kt - jt->sub_members->begin();
					*output_file << "               SUB_MEMBER NUMBER " << std::dec << idx_2 << std::endl
					<< "               Type: " << typeString[static_cast<uint32_t>(kt->type)] << ", PrimitiveType: " << primitiveString(kt->primitive) << ", Offset: 0x" << std::hex << kt
						->offset << ", Size: 0x" << std::hex << kt->size << std::endl;

					if (kt->data != nullptr && kt->primitive != Primitive::NONE)
					{
						*output_file << "               Data: ";
						switch (kt->primitive)
						{
						case (Primitive::UINT8_T):
						{
							uint8_t data;
							memcpy(&data, kt->data, 1);
							*output_file << std::dec << static_cast<unsigned short>(data);;
							break;
						}
						case (Primitive::UINT32_T):
						{
							uint32_t data;
							memcpy(&data, kt->data, 4);
							*output_file << std::dec << static_cast<unsigned long>(data);
							break;
						}
						case (Primitive::UINT64_T):
						{
							uint64_t data;
							memcpy(&data, kt->data, 8);
							*output_file << std::dec << static_cast<unsigned long long>(data);
							break;
						}
						case (Primitive::SINT32_T):
						{
							int32_t data;
							memcpy(&data, kt->data, 4);
							*output_file << std::dec << static_cast<long>(data);
							break;
						}
						case (Primitive::FLOAT):
						{
							float data;
							memcpy(&data, kt->data, 4);
							*output_file << std::dec << static_cast<float>(data);
							break;
						}
						default:
							break;

						}
						*output_file << std::endl;
					}

					if (kt->sub_members == nullptr || kt->sub_members->empty()) continue;
					for (auto lt = kt->sub_members->begin(); lt != kt->sub_members->end(); ++lt)
					{
						uint32_t idx_3 = lt - kt->sub_members->begin();
						*output_file << "                    SUB_SUB_MEMBER NUMBER " << std::dec << idx_3 << std::endl
						<< "                    Type: " << typeString[static_cast<uint32_t>(lt->type)] << ", PrimitiveType: " << primitiveString(lt->primitive) << ", Offset: 0x" << std::hex << lt
							->offset << ", Size: 0x" << std::hex << lt->size << std::endl;

						if (lt->data != nullptr && lt->primitive != Primitive::NONE)
						{
							*output_file << "                    Data: ";
							switch (lt->primitive)
							{
							case (Primitive::UINT8_T):
							{
								uint8_t data;
								memcpy(&data, lt->data, 1);
								*output_file << std::dec << static_cast<unsigned short>(data);;
								break;
							}
							case (Primitive::UINT32_T):
							{
								uint32_t data;
								memcpy(&data, lt->data, 4);
								*output_file << std::dec << static_cast<unsigned long>(data);
								break;
							}
							case (Primitive::UINT64_T):
							{
								uint64_t data;
								memcpy(&data, lt->data, 8);
								*output_file << std::dec << static_cast<unsigned long long>(data);
								break;
							}
							case (Primitive::SINT32_T):
							{
								int32_t data;
								memcpy(&data, lt->data, 4);
								*output_file << std::dec << static_cast<long>(data);
								break;
							}
							case (Primitive::FLOAT):
							{
								float data;
								memcpy(&data, lt->data, 4);
								*output_file << std::dec << static_cast<float>(data);
								break;
							}
							default:
								break;

							}
							*output_file << std::endl;
						}

						if (lt->sub_members == nullptr || lt->sub_members->empty()) continue;
						for (auto mt = lt->sub_members->begin(); mt != lt->sub_members->end(); ++mt)
						{
							uint32_t idx_4 = mt - lt->sub_members->begin();
							*output_file << "                         SUB_SUB_SUB_MEMBER NUMBER " << std::dec << idx_4 << std::endl
							<< "                         Type: " << typeString[static_cast<uint32_t>(mt->type)] << ", PrimitiveType: " << primitiveString(mt->primitive) << ", Offset: 0x" << std::hex << mt
								->offset << ", Size: 0x" << std::hex << mt->size << std::endl;

							if (mt->data != nullptr && mt->primitive != Primitive::NONE)
							{
								*output_file << "                         Data: ";
								switch (mt->primitive)
								{
								case (Primitive::UINT8_T):
								{
									uint8_t data;
									memcpy(&data, mt->data, 1);
									*output_file << std::dec << static_cast<unsigned short>(data);
									break;
								}
								case (Primitive::UINT32_T):
								{
									uint32_t data;
									memcpy(&data, mt->data, 4);
									*output_file << std::dec << static_cast<unsigned long>(data);
									break;
								}
								case (Primitive::UINT64_T):
								{
									uint64_t data;
									memcpy(&data, mt->data, 8);
									*output_file << std::dec << static_cast<unsigned long long>(data);
									break;
								}
								case (Primitive::SINT32_T):
								{
									int32_t data;
									memcpy(&data, mt->data, 4);
									*output_file << std::dec << static_cast<long>(data);
									break;
								}
								case (Primitive::FLOAT):
								{
									float data;
									memcpy(&data, mt->data, 4);
									*output_file << std::dec << static_cast<float>(data);
									break;
								}
								default:
									break;

								}
								*output_file << std::endl;
							}

							if (mt->sub_members == nullptr || mt->sub_members->empty()) continue;
							for (auto nt = mt->sub_members->begin(); nt != mt->sub_members->end(); ++nt)
							{
								uint32_t idx_5 = nt - mt->sub_members->begin();
								*output_file << "                              SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << idx_5 << std::endl
								<< "                              Type: " << typeString[static_cast<uint32_t>(nt->type)] << ", PrimitiveType: " << primitiveString(nt->primitive) << ", Offset: 0x" << std::hex << nt
									->offset << ", Size: 0x" << std::hex << nt->size << std::endl;

								if (nt->data != nullptr && nt->primitive != Primitive::NONE)
								{
									*output_file << "                              Data: ";
									switch (nt->primitive)
									{
									case (Primitive::UINT8_T):
									{
										uint8_t data;
										memcpy(&data, nt->data, 1);
										*output_file << std::dec << static_cast<unsigned short>(data);
										break;
									}
									case (Primitive::UINT32_T):
									{
										uint32_t data;
										memcpy(&data, nt->data, 4);
										*output_file << std::dec << static_cast<unsigned long>(data);
										break;
									}
									case (Primitive::UINT64_T):
									{
										uint64_t data;
										memcpy(&data, nt->data, 8);
										*output_file << std::dec << static_cast<unsigned long long>(data);
										break;
									}
									case (Primitive::SINT32_T):
									{
										int32_t data;
										memcpy(&data, nt->data, 4);
										*output_file << std::dec << static_cast<long>(data);
										break;
									}
									case (Primitive::FLOAT):
									{
										float data;
										memcpy(&data, nt->data, 4);
										*output_file << std::dec << static_cast<float>(data);
										break;
									}
									default:
										break;

									}
									*output_file << std::endl;
								}

								if (nt->sub_members == nullptr || nt->sub_members->empty()) continue;
								for (auto ot = nt->sub_members->begin(); ot != nt->sub_members->end(); ++ot)
								{
									uint32_t idx_6 = ot - nt->sub_members->begin();
									*output_file << "                                   SUB_SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << idx_6 << std::endl
									<< "                                   Type: " << typeString[static_cast<uint32_t>(ot->type)] << ", PrimitiveType: " << primitiveString(ot->primitive) << ", Offset: 0x" << std::hex << ot
										->offset << ", Size: 0x" << std::hex << ot->size << std::endl;

									if (ot->data != nullptr && ot->primitive != Primitive::NONE)
									{
										*output_file << "                                   Data: ";
										switch (ot->primitive)
										{
										case (Primitive::UINT8_T):
										{
											uint8_t data;
											memcpy(&data, ot->data, 1);
											*output_file << std::dec << static_cast<unsigned short>(data);
											break;
										}
										case (Primitive::UINT32_T):
										{
											uint32_t data;
											memcpy(&data, ot->data, 4);
											*output_file << std::dec << static_cast<unsigned long>(data);
											break;
										}
										case (Primitive::UINT64_T):
										{
											uint64_t data;
											memcpy(&data, ot->data, 8);
											*output_file << std::dec << static_cast<unsigned long long>(data);
											break;
										}
										case (Primitive::SINT32_T):
										{
											int32_t data;
											memcpy(&data, ot->data, 4);
											*output_file << std::dec << static_cast<long>(data);
											break;
										}
										case (Primitive::FLOAT):
										{
											float data;
											memcpy(&data, ot->data, 4);
											*output_file << std::dec << static_cast<float>(data);
											break;
										}
										default:
											break;

										}
										*output_file << std::endl;
									}

									if (ot->sub_members == nullptr || ot->sub_members->empty()) continue;
									for (auto pt = ot->sub_members->begin(); pt != ot->sub_members->end(); ++pt)
									{
										uint32_t idx_7 = pt - ot->sub_members->begin();
										*output_file << "                                        SUB_SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << idx_7 << std::endl
										<< "                                        Type: " << typeString[static_cast<uint32_t>(pt->type)] << ", PrimitiveType: " << primitiveString(pt->primitive) << ", Offset: 0x" << std::hex << pt
											->offset << ", Size: 0x" << std::hex << pt->size << std::endl;

										if (pt->data != nullptr && pt->primitive != Primitive::NONE)
										{
											*output_file << "                                        Data: ";
											switch (pt->primitive)
											{
											case (Primitive::UINT8_T):
											{
												uint8_t data;
												memcpy(&data, pt->data, 1);
												*output_file << std::dec << static_cast<unsigned short>(data);
												break;
											}
											case (Primitive::UINT32_T):
											{
												uint32_t data;
												memcpy(&data, pt->data, 4);
												*output_file << std::dec << static_cast<unsigned long>(data);
												break;
											}
											case (Primitive::UINT64_T):
											{
												uint64_t data;
												memcpy(&data, pt->data, 8);
												*output_file << std::dec << static_cast<unsigned long long>(data);
												break;
											}
											case (Primitive::SINT32_T):
											{
												int32_t data;
												memcpy(&data, pt->data, 4);
												*output_file << std::dec << static_cast<long>(data);
												break;
											}
											case (Primitive::FLOAT):
											{
												float data;
												memcpy(&data, pt->data, 4);
												*output_file << std::dec << static_cast<float>(data);
												break;
											}
											default:
												break;

											}
											*output_file << std::endl;
										}

										if (pt->sub_members == nullptr || pt->sub_members->empty()) continue;
										for (auto qt = pt->sub_members->begin(); qt != pt->sub_members->end(); ++qt)
										{
											uint32_t idx_8 = qt - pt->sub_members->begin();
											*output_file << "                                             SUB_SUB_SUB_SUB_SUB_MEMBER NUMBER: " << std::dec << idx_8 << std::endl
											<< "                                             Type: " << typeString[static_cast<uint32_t>(qt->type)] << ", PrimitiveType: " << primitiveString(qt->primitive) << ", Offset: 0x" << std::hex << qt
												->offset << ", Size: 0x" << std::hex << qt->size << std::endl;

											if (qt->data != nullptr && qt->primitive != Primitive::NONE)
											{
												*output_file << "                                             Data: ";
												switch (qt->primitive)
												{
												case (Primitive::UINT8_T):
												{
													uint8_t data;
													memcpy(&data, qt->data, 1);
													*output_file << std::dec << static_cast<unsigned short>(data);
													break;
												}
												case (Primitive::UINT32_T):
												{
													uint32_t data;
													memcpy(&data, qt->data, 4);
													*output_file << std::dec << static_cast<unsigned long>(data);
													break;
												}
												case (Primitive::UINT64_T):
												{
													uint64_t data;
													memcpy(&data, qt->data, 8);
													*output_file << std::dec << static_cast<unsigned long long>(data);
													break;
												}
												case (Primitive::SINT32_T):
												{
													int32_t data;
													memcpy(&data, qt->data, 4);
													*output_file << std::dec << static_cast<long>(data);
													break;
												}
												case (Primitive::FLOAT):
												{
													float data;
													memcpy(&data, qt->data, 4);
													*output_file << std::dec << static_cast<float>(data);
													break;
												}
												default:
													break;

												}
												*output_file << std::endl;
											}
										}
									}
								}
							}
						}
					}
				}

				*output_file << std::endl;
			}
		}
		
		output_file->close();
		delete output_file;
	}

	// console output group infos
	if (success && flag_ocg)
	{
		for (int i = 0; i < 8; i++)
		{
			if (mask_ocg.at(i) == false) continue;
			std::string animal;
			switch (i)
			{
			case (0):
				animal = "Moose";
				break;
			case (1):
				animal = "Jackrabbit";
				break;
			case (2):
				animal = "Mallard";
				break;
			case (3):
				animal = "Black Bear";
				break;
			case (4):
				animal = "Roosevelt Elk";
				break;
			case (5):
				animal = "Coyote";
				break;
			case (6):
				animal = "Blacktail Deer";
				break;
			case (7):
				animal = "Whitetail Deer";
				break;
			default:
				break;
			}

			uint32_t total_number_of_animals = 0;
			uint32_t number_of_groups = adf->GetNumberOfGroups(LaytonAnimal(i));
			std::cout << animal.c_str() << " Groups [ #" << number_of_groups << " ]" << std::endl;

			for (uint32_t j = 0; j < number_of_groups; j++)
			{	
				uint32_t group_size = adf->GetGroupSize(LaytonAnimal(i), j);
				total_number_of_animals += group_size;
				
				std::cout << std::endl << "           " << "[ " << j << " | #" << std::setw(2) << group_size
					<< " | " << std::setw(0) << adf->GetSpawnAreaId(LaytonAnimal(i), j) << " ]" << std::endl;

				for (uint32_t k = 0; k < group_size; k++)
				{
					std::string gender_arr[2] = { "Male", "Female" };
					uint8_t ui_gender = adf->GetGender(LaytonAnimal(i), j, k);
					std::string gender = gender_arr[ui_gender - 1];
					float weight = adf->GetWeight(LaytonAnimal(i), j, k);
					float score = adf->GetScore(LaytonAnimal(i), j, k);
					bool is_great_one = adf->IsGreatOne(LaytonAnimal(i), j, k);
					uint32_t visual_variation_seed = adf->GetVisualVariationSeed(LaytonAnimal(i), j, k);

					std::cout << "[ " << k
						<< " | " << std::setw(6) << gender.c_str()
						<< " | " << std::setw(7) << weight
						<< " | " << std::setw(8) << score
						<< " | " << std::setw(1) << is_great_one
						<< " | " << std::setw(5) << visual_variation_seed
						<< " ]" << std::endl;
				}
			}

			std::cout << std::endl << "Total number of animals: " << static_cast<int>(total_number_of_animals) << std::endl << std::endl;
		}
	}

	if (success && flag_rep)
	{
		// Custom input
		if (mask_rep.at(0) == true)
		{
			std::string name;
			std::string gender;
			float weight;
			float score;
			uint8_t is_great_one;
			uint32_t visual_variation_seed;

			std::cout << std::setw(23) << "Name: "; std::cin >> name;
			std::cout << std::setw(23) << "Gender: "; std::cin >> gender;
			std::cout << std::setw(23) << "Weight: "; std::cin >> weight;
			std::cout << std::setw(23) << "Score: "; std::cin >> score;
			std::cout << std::setw(23) << "Is Great One: "; std::cin >> is_great_one;
			std::cout << std::setw(23) << "Visual Variation Seed: "; std::cin >> visual_variation_seed;

			AnimalData *animal_data = new AnimalData(AnimalData::ResolveId(0, name), AnimalData::ResolveGender(gender), weight, score, is_great_one, visual_variation_seed);
			adf->ReplaceAnimal(animal_data);
			delete animal_data;
		}

		// Preset input
		else if (mask_rep.at(1) == true)
		{
			
		}
	}

	delete mask_ocg_values;
	delete adf;
	
	return 0;
}