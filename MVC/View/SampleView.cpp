#include "SampleView.h"

#include <iostream>

namespace View
{
    int SampleView::ShowMenuAndGetChoice()
    {
        std::cout << "\n--- 시료 관리 ---\n";
        std::cout << "1. 시료 등록\n";
        std::cout << "2. 시료 조회\n";
        std::cout << "3. 시료 검색\n";
        std::cout << "0. 뒤로가기\n";
        std::cout << "선택: ";

        int choice = -1;
        std::cin >> choice;
        return choice;
    }

    void SampleView::ShowList(const std::vector<Model::Sample>& samples)
    {
        std::cout << "\n[시료 목록] 총 " << samples.size() << "건\n";
        for (const auto& sample : samples)
        {
            std::cout << "- #" << sample.id << " " << sample.name
                       << " (재고 " << sample.stock << ")\n";
        }
    }

    void SampleView::ShowSearchResult(const std::optional<Model::Sample>& sample)
    {
        if (sample.has_value())
        {
            std::cout << "검색 결과: #" << sample->id << " " << sample->name
                       << " (재고 " << sample->stock << ")\n";
        }
        else
        {
            std::cout << "검색 결과가 없습니다.\n";
        }
    }

    void SampleView::ShowMessage(const std::string& message)
    {
        std::cout << message << "\n";
    }
}
