#pragma once

#include <optional>
#include <string>
#include <vector>

#include "../Model/Sample.h"

namespace View
{
    // 시료 관리 화면 - 등록 / 조회 / 검색
    class SampleView
    {
    public:
        static int ShowMenuAndGetChoice();
        static void ShowList(const std::vector<Model::Sample>& samples);
        static void ShowSearchResult(const std::optional<Model::Sample>& sample);
        static void ShowMessage(const std::string& message);
    };
}
