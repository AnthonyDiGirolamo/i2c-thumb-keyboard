#include <Wire.h>
#include "Tca8418Keyboard.h"

Tca8418Keyboard key_matrix(6, 10);

// uint32_t startmicros, endmicros;
void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("key_matrix.begin");
  key_matrix.begin();
  Serial.println("key_matrix.begin done");
}

void loop() {

  // uint8_t key;
  // key = key_matrix.get_key_event();
  // if (key > 0) {
  //   Serial.print((key&0x7F), HEX); //print keycode masking the key down/key up bit (bit7)
  //   if(key & 0x80) {
  //     Serial.println(" key down");
  //   } else {
  //     Serial.println(" key up");
  //   }
  // }

  if (key_matrix.update()) {
    Serial.print("pressed [");
    Serial.print(key_matrix.pressed_key_count);
    Serial.print("]: ");
    for (int i=0; i<key_matrix.pressed_key_count; i++) {
      Serial.print(key_matrix.pressed_list[i].row);
      Serial.print(",");
      Serial.print(key_matrix.pressed_list[i].col);
      Serial.print(",");
      Serial.print(key_matrix.pressed_list[i].hold_time);
      Serial.print("  ");
    }
    Serial.println();

    Serial.print("released [");
    Serial.print(key_matrix.released_key_count);
    Serial.print("]: ");
    for (int i=0; i<key_matrix.released_key_count; i++) {
      Serial.print(key_matrix.released_list[i].row);
      Serial.print(",");
      Serial.print(key_matrix.released_list[i].col);
      Serial.print("  ");
    }
    Serial.println();
  }

}
