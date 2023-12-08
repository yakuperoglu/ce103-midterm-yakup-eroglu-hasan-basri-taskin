#include <gtest/gtest.h>
#include "yachtsystem.h"
#include <sstream>
//bu olabilir //   #include "../../yachtsystem/header/yachtsystem.h" (de�ilmi�)

// son bu kald� //
class YachtsystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup test data
    }

    void TearDown() override {
        // Clean up test data
    }
};


using namespace Coruh::Yachtsystem;

// setName fonksiyonu i�in test
TEST(SeaVehicleTest, SetName) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setName("Yacht A")); // Ge�erli isim
    EXPECT_FALSE(vehicle.setName(""));       // Ge�ersiz isim
}

// setLength fonksiyonu i�in test
TEST(SeaVehicleTest, SetLength) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setLength(30));  // Ge�erli uzunluk
    EXPECT_FALSE(vehicle.setLength(-1)); // Ge�ersiz uzunluk
}

// setMaintanceStatus fonksiyonu i�in test
TEST(SeaVehicleTest, SetMaintanceStatus) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setMaintanceStatus("yes")); // Ge�erli durum
    EXPECT_TRUE(vehicle.setMaintanceStatus("no"));  // Ge�erli durum
    EXPECT_FALSE(vehicle.setMaintanceStatus("maybe")); // Ge�ersiz durum
}

// setOwner fonksiyonu i�in test
TEST(SeaVehicleTest, SetOwner) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setOwner("John Doe")); // Ge�erli sahip ismi
    EXPECT_FALSE(vehicle.setOwner(""));        // Ge�ersiz sahip ismi
}
// setCustomerName fonksiyonu i�in test
TEST(ReservationTest, SetCustomerName) {
    Reservation reservation;
    EXPECT_TRUE(reservation.setCustomerName("John Doe")); // Ge�erli m��teri ismi
    EXPECT_FALSE(reservation.setCustomerName(""));        // Ge�ersiz m��teri ismi
}

class ReservationTestWithOutput : public ::testing::Test {
protected:
    std::streambuf* originalCoutStreambuf;
    std::ostringstream capturedCout;

    void SetUp() override {
        originalCoutStreambuf = std::cout.rdbuf();
        std::cout.rdbuf(capturedCout.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(originalCoutStreambuf);
    }
};

// displayInfo fonksiyonu i�in test
TEST_F(ReservationTestWithOutput, DisplayInfo) {
    Reservation reservation;
    reservation.setCustomerName("John Doe");

    reservation.displayInfo();

    // ��kt�y� kontrol et
    std::string expectedOutput = "Reservation Name: John Doe, Date: \n"; // 'Date' alan� bo� b�rak�ld��� i�in b�yle olacak
    EXPECT_EQ(capturedCout.str(), expectedOutput);
}

// bu olabilir // (de�ilmi�)
int main(int argc, char** argv) {
#ifdef ENABLE_YACHTSYSTEM_TEST
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    return 0;
#endif
}
