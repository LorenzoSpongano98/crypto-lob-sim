#include "tf/feed/tls.hpp"

#include <boost/asio/ssl/context.hpp>
#include <boost/beast/websocket.hpp>

namespace tf::feed {

bool tls_client_context_ok() {
    namespace ssl = boost::asio::ssl;
    ssl::context ctx{ssl::context::tls_client};
    ctx.set_options(ssl::context::default_workarounds | ssl::context::no_sslv2 |
                    ssl::context::no_sslv3 | ssl::context::no_tlsv1 | ssl::context::no_tlsv1_1);
    ctx.set_verify_mode(ssl::verify_peer);
    return ctx.native_handle() != nullptr;
}

}
