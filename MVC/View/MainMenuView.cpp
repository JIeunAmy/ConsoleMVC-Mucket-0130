#include "MainMenuView.h"

#include <iostream>
#include <limits>

namespace View
{
    int MainMenuView::ShowAndGetChoice()
    {
        std::cout << "\n=== 반도체 시료 생산주문관리 시스템 ===\n";
        std::cout << "1. 시료 관리\n";
        std::cout << "2. 주문 (접수 / 승인 / 거절)\n";
        std::cout << "3. 모니터링\n";
        std::cout << "4. 출고 처리\n";
        std::cout << "5. 생산 라인\n";
        std::cout << "0. 종료\n";
        std::cout << "선택: ";

        int choice = -1;
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        return choice;
    }
}
