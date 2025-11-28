
#include "micronova_button.h"

namespace esphome {
namespace micronova {

void MicroNovaButton::press_action() {
  switch (this->get_function()) {
    case MicroNovaFunctions::STOVE_FUNCTION_CUSTOM: {
      uint8_t locations[] = {0x00, 0x20};
      for (uint8_t loc : locations) {
        for (uint16_t addr = 0x00; addr <= 0xFF; ++addr) {
          this->micronova_->queue_read_request(loc, static_cast<uint8_t>(addr));
        }
      }
      // Optional: Uncomment if you need write requests
      // this->micronova_->queue_write_request(this->memory_location_, this->memory_address_, this->memory_data_);
      break;
    }
    default:
      break;
  }
  this->micronova_->update();
}

}  // namespace micronova
}  // namespace esphome

