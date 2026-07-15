#pragma once

#include <vector>

#include "../Model/Order.h"
#include "../Model/ProductionLine.h"
#include "../Model/Sample.h"
#include "MonitoringController.h"
#include "OrderController.h"
#include "ProductionController.h"
#include "ReleaseController.h"
#include "SampleController.h"

namespace Controller
{
    // 메인 메뉴에서 각 기능별 컨트롤러로 라우팅
    class MainController
    {
    public:
        MainController();
        void Run();

    private:
        void RunSampleMenu();
        void RunOrderMenu();
        void RunMonitoringMenu();
        void RunReleaseMenu();
        void RunProductionMenu();

        std::vector<Model::Sample> samples_;
        std::vector<Model::Order> orders_;
        Model::ProductionLine line_;

        SampleController sampleController_;
        OrderController orderController_;
        MonitoringController monitoringController_;
        ReleaseController releaseController_;
        ProductionController productionController_;
    };
}
