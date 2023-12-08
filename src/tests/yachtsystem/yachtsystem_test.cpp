#include <gtest/gtest.h>
#include "yachtsystem.h"
#include <sstream>
//bu olabilir //   #include "../../yachtsystem/header/yachtsystem.h" (deðilmiþ)

// son bu kaldý //
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

// setName fonksiyonu için test
TEST(SeaVehicleTest, SetName) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setName("Yacht A")); // Geçerli isim
    EXPECT_FALSE(vehicle.setName(""));       // Geçersiz isim
}

// setLength fonksiyonu için test
TEST(SeaVehicleTest, SetLength) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setLength(30));  // Geçerli uzunluk
    EXPECT_FALSE(vehicle.setLength(-1)); // Geçersiz uzunluk
}

// setMaintanceStatus fonksiyonu için test
TEST(SeaVehicleTest, SetMaintanceStatus) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setMaintanceStatus("yes")); // Geçerli durum
    EXPECT_TRUE(vehicle.setMaintanceStatus("no"));  // Geçerli durum
    EXPECT_FALSE(vehicle.setMaintanceStatus("maybe")); // Geçersiz durum
}

// setOwner fonksiyonu için test
TEST(SeaVehicleTest, SetOwner) {
    SeaVehicle vehicle;
    EXPECT_TRUE(vehicle.setOwner("John Doe")); // Geçerli sahip ismi
    EXPECT_FALSE(vehicle.setOwner(""));        // Geçersiz sahip ismi
}
// setCustomerName fonksiyonu için test
TEST(ReservationTest, SetCustomerName) {
    Reservation reservation;
    EXPECT_TRUE(reservation.setCustomerName("John Doe")); // Geçerli müþteri ismi
    EXPECT_FALSE(reservation.setCustomerName(""));        // Geçersiz müþteri ismi
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

// displayInfo fonksiyonu için test
TEST_F(ReservationTestWithOutput, DisplayInfo) {
    Reservation reservation;
    reservation.setCustomerName("John Doe");

    reservation.displayInfo();

    // Çýktýyý kontrol et
    std::string expectedOutput = "Reservation Name: John Doe, Date: \n"; // 'Date' alaný boþ býrakýldýðý için böyle olacak
    EXPECT_EQ(capturedCout.str(), expectedOutput);
}

// bu olabilir // (deðilmiþ)
int main(int argc, char** argv) {
#ifdef ENABLE_YACHTSYSTEM_TEST
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    return 0;
#endif
}
