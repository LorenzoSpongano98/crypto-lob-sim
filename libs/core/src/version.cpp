#include "tf/core/version.hpp"

namespace tf {

std::string_view version() noexcept {
    return TF_VERSION;
}

}
