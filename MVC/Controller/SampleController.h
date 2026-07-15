#pragma once

#include <optional>
#include <string>
#include <vector>

#include "../Model/Sample.h"

namespace Controller
{
    // 시료 등록 / 조회 / 검색을 담당
    class SampleController
    {
    public:
        explicit SampleController(std::vector<Model::Sample>& samples);

        int Register(const std::string& name, double avgProductionTime, double yieldRate, int initialStock);
        const std::vector<Model::Sample>& List() const;
        std::optional<Model::Sample> FindByName(const std::string& name) const;

    private:
        std::vector<Model::Sample>& samples_;
    };
}
