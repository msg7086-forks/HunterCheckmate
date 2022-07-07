// Dear ImGui: standalone example application for DirectX 11
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "imgui_stdlib.h"
#include <d3d11.h>
#include <tchar.h>
#include <iostream>
#include "FileHandler.h"
#include "AnimalPopulation.h"
#include "ThpPlayerProfile.h"

// Data
static ID3D11Device*            g_pd3dDevice = NULL;
static ID3D11DeviceContext*     g_pd3dDeviceContext = NULL;
static IDXGISwapChain*          g_pSwapChain = NULL;
static ID3D11RenderTargetView*  g_mainRenderTargetView = NULL;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("Hunter Checkmate"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Hunter Checkmate"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;
    //io.ConfigViewportsNoDefaultParent = true;
    //io.ConfigDockingAlwaysTabBar = true;
    //io.ConfigDockingTransparentPayload = true;
    //io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleFonts;     // FIXME-DPI: Experimental. THIS CURRENTLY DOESN'T WORK AS EXPECTED. DON'T USE IN USER APP!
    //io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleViewports; // FIXME-DPI: Experimental.

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }
	style.FrameRounding = 5.0f;

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

	io.Fonts->AddFontFromFileTTF("fonts/CascadiaMono.ttf", 15.0f);

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	using namespace HunterCheckmate_FileAnalyzer;

	bool keep_open = true;
	boost::filesystem::path tmp_path = boost::filesystem::initial_path<boost::filesystem::path>();
	tmp_path = "C:\\Users\\oleSQL\\Documents\\thehunter working\\pop";
	std::string str_input_file_path = "C:\\Users\\oleSQL\\Documents\\thehunter working\\pop\\decomp_animal_population_0";
	boost::filesystem::path input_file_path = "C:\\Users\\oleSQL\\Documents\\thehunter working\\pop\\decomp_animal_population_0";
	boost::filesystem::path input_file_name = "decomp_animal_population_0";
	std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, input_file_path);
	std::shared_ptr<ReserveData> reserve_data = std::make_shared<ReserveData>(static_cast<uint8_t>(std::stoi(std::string(1, input_file_name.generic_string().back()))));
	std::unique_ptr<AnimalPopulation> animal_population = std::make_unique<AnimalPopulation>(file_handler, reserve_data);

	std::string animal = "";
	//bool collapsed = true;
	// idx, weight, score
	std::vector<bool> sort = { true, false, false, false, false };

    // Main loop
    bool done = false;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Start the Dear ImGui frame
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | 
										ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		const ImGuiViewport* viewport = ImGui::GetMainViewport();

		ImVec2 window_pos = viewport->WorkPos;
		ImVec2 window_size = viewport->WorkSize;

		ImGui::SetNextWindowPos(window_pos);
		ImGui::SetNextWindowSize(window_size);
		ImGui::SetNextWindowViewport(viewport->ID);

		ImGui::Begin("HunterCheckmate", NULL, window_flags);
		ImGui::BeginChild("file_path", ImVec2(ImGui::GetContentRegionAvail().x, 80.f), true);

		ImGui::Text("Enter the location of your decompiled population file:");

		ImGui::InputText(" ", &str_input_file_path);
		input_file_path = str_input_file_path;
		input_file_name = input_file_path.filename();


		if (ImGui::Button("Analyze"))
		{
			animal = "";
			file_handler = std::make_shared<FileHandler>(Endian::Little, input_file_path);
			reserve_data = std::make_shared<ReserveData>(static_cast<uint8_t>(std::stoi(std::string(1, input_file_name.generic_string().back()))));
			animal_population = std::make_unique<AnimalPopulation>(file_handler, reserve_data);
			if (animal_population->Deserialize())
			{
				animal_population->MapAnimals();
				std::cout << "[DEBUG] Successfully analyzed population file!\n";
			}
		}

		ImGui::EndChild();

		ImGui::BeginChild("info", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true);

		ImGui::BeginChild("sort", ImVec2(ImGui::GetContentRegionAvail().x, 80.f), false);

		ImGui::Text("Show");


		if (animal_population->m_initialized && animal_population->m_valid)
		{
			auto it_group = animal_population->m_animals.begin();
			for (; it_group != animal_population->m_animals.end(); ++it_group)
			{
				std::string show_animal = it_group->second.at(0).m_name;
				std::vector<AnimalGroup> groups;
				ImGui::SameLine();
				if (ImGui::Button(show_animal.c_str()))
				{
					animal = show_animal;
				}
			}
		}

		ImGui::Text("Sort by ");
		ImGui::SameLine();
		if (ImGui::Button("Index"))
		{
			sort = { true, false, false, false, false };
		}
		ImGui::SameLine();
		if (ImGui::Button("Score Down"))
		{
			sort = { false, true, false , false, false};
		}		
		ImGui::SameLine();
		if (ImGui::Button("Score Up"))
		{
			sort = { false, false, true, false, false };
		}
		ImGui::SameLine();
		if (ImGui::Button("Weight Down"))
		{
			sort = { false, false, false, true, false };
		}
		ImGui::SameLine();
		if (ImGui::Button("Weight Up"))
		{
			sort = { false, false, false, false, true };
		}


		//if (ImGui::Button("Show|Hide"))
		//{
		//	if (collapsed)
		//	{
		//		collapsed = false;
		//	}
		//	else
		//	{
		//		collapsed = true;
		//	}
		//}

		ImGui::EndChild();
		
		if (animal_population->m_initialized && animal_population->m_valid) 
		{
			if (animal != "")
			{
				const AnimalType animal_type = Animal::ResolveAnimalType(animal);
				std::vector<AnimalGroup> groups = animal_population->m_animals.at(animal_type);
				uint32_t total_animals = 0;

				if (sort.at(0))
					std::sort(groups.begin(), groups.end(), AnimalPopulation::cmpIdx);
				else if (sort.at(1))
					std::sort(groups.begin(), groups.end(), AnimalPopulation::cmpHighestScore);
				else if (sort.at(2))
					std::sort(groups.begin(), groups.end(), AnimalPopulation::cmpLowestScore);
				else if (sort.at(3))
					std::sort(groups.begin(), groups.end(), AnimalPopulation::cmpHighestWeight);
				else if (sort.at(4))
					std::sort(groups.begin(), groups.end(), AnimalPopulation::cmpLowestWeight);

				auto it_beg = groups.begin();
				for (; it_beg != groups.end(); ++it_beg)
				{
					std::ostringstream group_info;
					group_info << "[ " << std::setw(3) << it_beg->m_index
						<< " | #" << std::setw(2) << it_beg->m_size
						<< " | " << std::setw(12) << it_beg->m_spawn_area_id
						<< " | " << std::setw(8) << it_beg->m_max_weight
						<< " | " << std::setw(8) << it_beg->m_max_score
						<< " ]";

					//if (collapsed == false)
					//{
					//	ImGui::SetNextItemOpen(true, ImGuiCond_Always);
					//}
					//else
					//{
					//	ImGui::SetNextItemOpen(false, ImGuiCond_Always);
					//}

					if (sort.at(0))
						std::sort(it_beg->m_animals.begin(), it_beg->m_animals.end(), AnimalGroup::cmpIdx);
					else if (sort.at(1))
						std::sort(it_beg->m_animals.begin(), it_beg->m_animals.end(), AnimalGroup::cmpHighestScore);
					else if (sort.at(2))
						std::sort(it_beg->m_animals.begin(), it_beg->m_animals.end(), AnimalGroup::cmpLowestScore);
					else if (sort.at(3))
						std::sort(it_beg->m_animals.begin(), it_beg->m_animals.end(), AnimalGroup::cmpHighestWeight);
					else if (sort.at(4))
						std::sort(it_beg->m_animals.begin(), it_beg->m_animals.end(), AnimalGroup::cmpLowestWeight);

					if (ImGui::TreeNode((void*)&it_beg->m_spawn_area_id, group_info.str().c_str()))
					{
						auto it_animal_beg = it_beg->m_animals.begin();
						for (; it_animal_beg != it_beg->m_animals.end(); ++it_animal_beg)
						{
							std::ostringstream animal_info;
							animal_info << "[ " << std::setw(2) << it_animal_beg->m_idx
								<< " | " << std::setw(6) << it_animal_beg->m_gender
								<< " | " << std::setw(8) << it_animal_beg->m_weight
								<< " | " << std::setw(8) << it_animal_beg->m_score
								<< " | " << std::setw(1) << static_cast<int>(it_animal_beg->m_is_great_one)
								<< " | " << std::setw(15) << it_animal_beg->m_fur_type
								<< " | " << std::setw(2) << static_cast<unsigned int>(it_animal_beg->m_fur_type_id)
								<< " | " << std::setw(10) << it_animal_beg->m_visual_variation_seed
								<< " ]";
							ImGui::Text(animal_info.str().c_str());
						}
						ImGui::TreePop();
					}

				}
			}
		}

		ImGui::EndChild();

		ImGui::End();

        ImGui::ShowDemoWindow();


        // Rendering
        ImGui::Render();
        const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        g_pSwapChain->Present(1, 0); // Present with vsync
        //g_pSwapChain->Present(0, 0); // Present without vsync
    }

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E0 // From Windows SDK 8.1+ headers
#endif

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    case WM_DPICHANGED:
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)
        {
            //const int dpi = HIWORD(wParam);
            //printf("WM_DPICHANGED to %d (%.0f%%)\n", dpi, (float)dpi / 96.0f * 100.0f);
            const RECT* suggested_rect = (RECT*)lParam;
            ::SetWindowPos(hWnd, NULL, suggested_rect->left, suggested_rect->top, suggested_rect->right - suggested_rect->left, suggested_rect->bottom - suggested_rect->top, SWP_NOZORDER | SWP_NOACTIVATE);
        }
        break;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
