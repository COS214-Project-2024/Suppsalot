
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "CitizensManager.h"
#include "HighClassCitizen.h"
#include "MidClassCitizen.h"
#include "LowClassCitizen.h"
#include <sstream>

// Test helper class that inherits from CitizensManager to expose protected members
class TestableCitizensManager : public CitizensManager {
public:
    // Expose protected members for testing
    using CitizensManager::citizens;
    using CitizensManager::totalSatisfaction;


    // Mock input for testing
    int mockGetValidatedChoice(int min, int max, int mockValue) {
        return mockValue >= min && mockValue <= max ? mockValue : min;
    }

    size_t getCitizenCount() const {
        return citizens.size();
    }

    float getTotalSatisfaction() const {
        return totalSatisfaction;
    }
};

TEST_CASE("CitizensManager - Basic Initialization") {
    TestableCitizensManager manager;

    CHECK(manager.getCitizenCount() == 0);
    CHECK(manager.getTotalSatisfaction() == 0.0f);
    CHECK(manager.getAverageSatisfaction() == 0.0f);
}

TEST_CASE("CitizensManager - Creating Citizens") {
    TestableCitizensManager manager;

    SUBCASE("Create High Class Citizens") {
        const int initialCount = manager.getCitizenCount();
        const float initialSatisfaction = manager.getTotalSatisfaction();

        // Add 3 high class citizens
        for (int i = 0; i < 3; ++i) {
            std::unique_ptr<PrototypeCitizen> highCitizen = std::make_unique<HighClassCitizen>();
            float citizenSatisfaction = highCitizen->getSatisfaction();
            manager.totalSatisfaction += citizenSatisfaction;
            manager.citizens.push_back(std::move(highCitizen));
        }

        CHECK(manager.getCitizenCount() == initialCount + 3);
        CHECK(manager.getTotalSatisfaction() > initialSatisfaction);
        CHECK(HighClassCitizen::getHighClassCount() == 3);
    }

    SUBCASE("Create Mixed Class Citizens") {
        // Add one of each class
        std::unique_ptr<PrototypeCitizen> high = std::make_unique<HighClassCitizen>();
        std::unique_ptr<PrototypeCitizen> mid = std::make_unique<MidClassCitizen>();
        std::unique_ptr<PrototypeCitizen> low = std::make_unique<LowClassCitizen>();

        float totalSat = high->getSatisfaction() + mid->getSatisfaction() + low->getSatisfaction();

        manager.totalSatisfaction += high->getSatisfaction();
        manager.citizens.push_back(std::move(high));
        manager.totalSatisfaction += mid->getSatisfaction();
        manager.citizens.push_back(std::move(mid));
        manager.totalSatisfaction += low->getSatisfaction();
        manager.citizens.push_back(std::move(low));

        CHECK(manager.getCitizenCount() == 3);
        CHECK(manager.getTotalSatisfaction() == doctest::Approx(totalSat));
        CHECK(manager.getAverageSatisfaction() == doctest::Approx(totalSat / 3));
    }
}

TEST_CASE("CitizensManager - Employment Toggle") {
    TestableCitizensManager manager;

    // Add one high class citizen
    std::unique_ptr<PrototypeCitizen> citizen = std::make_unique<HighClassCitizen>();
    bool initialEmployment = citizen->getIsEmployed();
    manager.citizens.push_back(std::move(citizen));

    // Toggle employment
    manager.citizens[0]->toggleEmployment();

    CHECK(manager.citizens[0]->getIsEmployed() != initialEmployment);
}

TEST_CASE("CitizensManager - Killing Citizens") {
    TestableCitizensManager manager;

    // Add 5 citizens
    for (int i = 0; i < 5; ++i) {
        std::unique_ptr<PrototypeCitizen> citizen = std::make_unique<MidClassCitizen>();
        manager.totalSatisfaction += citizen->getSatisfaction();
        manager.citizens.push_back(std::move(citizen));
    }

    const size_t initialCount = manager.getCitizenCount();
    const float initialSatisfaction = manager.getTotalSatisfaction();

    // Kill 2 citizens
    for (int i = 0; i < 2; ++i) {
        if (!manager.citizens.empty()) {
            manager.totalSatisfaction -= manager.citizens[0]->getSatisfaction();
            manager.citizens.erase(manager.citizens.begin());
        }
    }

    CHECK(manager.getCitizenCount() == initialCount - 2);
    CHECK(manager.getTotalSatisfaction() < initialSatisfaction);
}

TEST_CASE("CitizensManager - Average Satisfaction") {
    TestableCitizensManager manager;

    SUBCASE("Empty Citizens List") {
        CHECK(manager.getAverageSatisfaction() == 0.0f);
    }

    SUBCASE("Multiple Citizens") {
        // Add citizens with known satisfaction values
        std::unique_ptr<PrototypeCitizen> high = std::make_unique<HighClassCitizen>();
        std::unique_ptr<PrototypeCitizen> mid = std::make_unique<MidClassCitizen>();

        float highSat = high->getSatisfaction();
        float midSat = mid->getSatisfaction();

        manager.totalSatisfaction += highSat;
        manager.citizens.push_back(std::move(high));
        manager.totalSatisfaction += midSat;
        manager.citizens.push_back(std::move(mid));

        float expectedAverage = (highSat + midSat) / 2.0f;
        CHECK(manager.getAverageSatisfaction() == doctest::Approx(expectedAverage));
    }
}

TEST_CASE("CitizensManager - Progress Year") {
    TestableCitizensManager manager;
    
    // Add some citizens
    for (int i = 0; i < 3; ++i) {
        std::unique_ptr<PrototypeCitizen> citizen = std::make_unique<LowClassCitizen>();
        manager.citizens.push_back(std::move(citizen));
    }
    
    // Progress year and verify it doesn't crash
    CHECK_NOTHROW(manager.progressYear());
}