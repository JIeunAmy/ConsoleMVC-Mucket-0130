#include "MainController.h"

#include <iostream>
#include <string>

#include "../View/MainMenuView.h"
#include "../View/MonitoringView.h"
#include "../View/OrderView.h"
#include "../View/ProductionLineView.h"
#include "../View/ReleaseView.h"
#include "../View/SampleView.h"

namespace Controller
{
    MainController::MainController()
        : sampleController_(samples_)
        , orderController_(orders_, samples_, line_)
        , monitoringController_(orders_, samples_)
        , releaseController_(orders_)
        , productionController_(orders_, samples_, line_)
    {
    }

    void MainController::Run()
    {
        bool running = true;
        while (running)
        {
            switch (View::MainMenuView::ShowAndGetChoice())
            {
            case 1: RunSampleMenu();     break;
            case 2: RunOrderMenu();      break;
            case 3: RunMonitoringMenu(); break;
            case 4: RunReleaseMenu();    break;
            case 5: RunProductionMenu(); break;
            case 0: running = false;     break;
            default:
                View::SampleView::ShowMessage("잘못된 선택입니다.");
                break;
            }
        }
    }

    void MainController::RunSampleMenu()
    {
        switch (View::SampleView::ShowMenuAndGetChoice())
        {
        case 1:
        {
            std::string name;
            double avgTime = 0.0;
            double yieldRate = 1.0;
            int stock = 0;
            std::cout << "이름 평균생산시간 수율 초기재고: ";
            std::cin >> name >> avgTime >> yieldRate >> stock;
            int id = sampleController_.Register(name, avgTime, yieldRate, stock);
            View::SampleView::ShowMessage("등록 완료: #" + std::to_string(id));
            break;
        }
        case 2:
            View::SampleView::ShowList(sampleController_.List());
            break;
        case 3:
        {
            std::string name;
            std::cout << "검색할 이름: ";
            std::cin >> name;
            View::SampleView::ShowSearchResult(sampleController_.FindByName(name));
            break;
        }
        default:
            break;
        }
    }

    void MainController::RunOrderMenu()
    {
        switch (View::OrderView::ShowMenuAndGetChoice())
        {
        case 1:
        {
            int sampleId = 0;
            std::string customerName;
            int quantity = 0;
            std::cout << "시료ID 고객명 수량: ";
            std::cin >> sampleId >> customerName >> quantity;
            int id = orderController_.PlaceOrder(sampleId, customerName, quantity);
            View::OrderView::ShowMessage("접수 완료: #" + std::to_string(id));
            break;
        }
        case 2:
        {
            View::OrderView::ShowList(orderController_.List());
            int orderId = 0;
            std::cout << "승인할 주문 ID: ";
            std::cin >> orderId;
            View::OrderView::ShowMessage(orderController_.Approve(orderId) ? "승인 처리 완료" : "승인 실패");
            break;
        }
        case 3:
        {
            View::OrderView::ShowList(orderController_.List());
            int orderId = 0;
            std::cout << "거절할 주문 ID: ";
            std::cin >> orderId;
            View::OrderView::ShowMessage(orderController_.Reject(orderId) ? "거절 처리 완료" : "거절 실패");
            break;
        }
        default:
            break;
        }
    }

    void MainController::RunMonitoringMenu()
    {
        View::MonitoringView::ShowOrderSummary(monitoringController_.SummarizeOrders());
        View::MonitoringView::ShowStockStatus(monitoringController_.SummarizeStock());
    }

    void MainController::RunReleaseMenu()
    {
        View::ReleaseView::ShowConfirmedList(releaseController_.List());
        int orderId = 0;
        std::cout << "출고 처리할 주문 ID: ";
        std::cin >> orderId;
        View::ReleaseView::ShowMessage(releaseController_.Release(orderId) ? "출고 완료" : "출고 실패");
    }

    void MainController::RunProductionMenu()
    {
        View::ProductionLineView::ShowPendingQueue(productionController_.PendingOrderIds());
        View::ProductionLineView::ShowProductionResult(productionController_.ProcessNext());
    }
}
