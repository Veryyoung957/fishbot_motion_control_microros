#include "fishbot_display.h"

void FishBotDisplay::init()
{
    Wire.begin(18, 19, 400000UL);
    _display = Adafruit_SSD1306(128, 64, &Wire);
    _display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 设置OLED的I2C地址
    _display.clearDisplay();                    // 清空屏幕
    _display.setTextSize(1);                    // 设置字体大小
    _display.setTextColor(SSD1306_WHITE);       // 设置字体颜色
    _display.setCursor(16, 16);                 // 设置开始显示文字的坐标
    _display.println("  [fishbot-v1.0.0]");     // 输出的字符
    _display.display();                         // 使更改的显示生效
}

FishBotDisplay::FishBotDisplay()
{
}

void FishBotDisplay::updateDisplay()
{
    if (millis() - last_update_time > update_interval)
    {

        last_update_time = millis();
        _display.clearDisplay();
        _display.setCursor(0, 0);
        _display.println("   -fishbot-v1.0.0-");
        _display.println("");
        _display.print("voltage:");
        _display.println(battery_info_);
        _display.print("linear :");
        _display.println(bot_linear_);
        _display.print("angular:");
        _display.println(bot_angular_);
        _display.display();
    }
}
void FishBotDisplay::updateBatteryInfo(float &battery_info)
{
    battery_info_ = battery_info;
}
void FishBotDisplay::updateUltrasoundDist(float &ultrasound_distance)
{
    ultrasound_distance_ = ultrasound_distance;
}
void FishBotDisplay::updateBotAngular(float &bot_angular)
{
    bot_angular_ = bot_angular;
}
void FishBotDisplay::updateBotLinear(float &bot_linear)
{
    bot_linear_ = bot_linear;
}