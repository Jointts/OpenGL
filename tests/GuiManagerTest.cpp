#include <gtest/gtest.h>
#include "../src/gui/GuiManager.h"
#include "../src/display/DisplayManager.h"
#include "../src/gui/Button.h"

TEST(GuiManager, CalculateNextCollisionColor) { // NOLINT
    DisplayManager::getInstance();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    for (int i = 1; i < 256; ++i) {
        GuiWidget *button = new GuiWidget(100, 100);
        if (i < 256) {
            EXPECT_FLOAT_EQ(button->collisionColor.r, i);
        }
    }

}