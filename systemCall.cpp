#include <memory>
#include <stdexcept>
#include <array>

std::string execSystemCall_StdString(const std::string& cmd) {
    std::array<char, 128> buffer{};
    std::string result;

    auto closer = [](FILE* f) { pclose(f); };
    std::unique_ptr<FILE, decltype(closer)> pipe(popen(cmd.c_str(), "r"), closer);
    if (!pipe) throw std::runtime_error("popen failed");

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        result += buffer.data();
    return result;
}