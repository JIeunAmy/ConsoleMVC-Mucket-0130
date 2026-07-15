#include "SampleController.h"

namespace Controller
{
    SampleController::SampleController(std::vector<Model::Sample>& samples)
        : samples_(samples)
    {
    }

    int SampleController::Register(const std::string& name, double avgProductionTime, double yieldRate, int initialStock)
    {
        Model::Sample sample;
        sample.id = static_cast<int>(samples_.size()) + 1;
        sample.name = name;
        sample.avgProductionTime = avgProductionTime;
        sample.yieldRate = yieldRate;
        sample.stock = initialStock;

        samples_.push_back(sample);
        return sample.id;
    }

    const std::vector<Model::Sample>& SampleController::List() const
    {
        return samples_;
    }

    std::optional<Model::Sample> SampleController::FindByName(const std::string& name) const
    {
        for (const auto& sample : samples_)
        {
            if (sample.name == name)
            {
                return sample;
            }
        }
        return std::nullopt;
    }
}
