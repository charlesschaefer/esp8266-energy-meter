#include <SmingCore.h>
#include <Libraries/Adafruit_GFX/Adafruit_GFX.h>
#include <Libraries/Adafruit_SSD1306/Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

// to use other kind of display supported by library, eg. SH1106 1.3in:
#undef SSD1306_128_64  // this one is default, 0.96in SSD1306
#define SSD1306_128_32  // muda o tipo de display

// valores default do constructor não funcionaram, então repetindo o mesmo valor de antes.
Adafruit_SSD1306 display(OLED_RESET);

void Demo2()
{
	Serial.println("Display: some text");
	display.clearDisplay();
	// text display tests
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.println("Sming Framework");
	display.setTextColor(BLACK, WHITE); // 'inverted' text
	display.setCursor(104, 7);
	display.println("v1.0");
	//----
	display.setTextColor(WHITE);
	display.println("Let's do smart things");
	display.setTextSize(3);
	display.print("IoT");
	display.display();
}

void init() {
	Serial.begin(SERIAL_BAUD_RATE);
    Serial.systemDebugOutput(false); // Allow debug print to serial
    Serial.commandProcessing(false);

    Serial.println("Display: start");

	// by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
	// initialize with the I2C addr 0x3c (for the 128x64)
	// bool:reset set to TRUE or FALSE depending on your display
	display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
	display.display();

	delay(2000);

	// Clear the buffer
	display.clearDisplay();

	// Draw a single pixel in white
	display.drawPixel(10, 10, WHITE);

	// Show the display buffer on the screen. You MUST call display() after
	// drawing commands to make them visible on screen!
	display.display();
	delay(2000);

	Demo2();	
}

