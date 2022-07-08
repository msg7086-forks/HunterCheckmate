#pragma once

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalSettings
	{
	public:
		float m_female_weight_min;
		float m_female_weight_max;
		float m_male_weight_min;
		float m_male_weight_max;
		float m_female_score_min;
		float m_female_score_max;
		float m_male_score_min;
		float m_male_score_max;

		AnimalSettings() = default;
		~AnimalSettings() = default;
	};
}