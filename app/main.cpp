#include <Eigen/Eigen>
#include <fmt/base.h>
#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include <cstdlib>
#include <sstream>
#include <fstream>

namespace Eigen {

template <typename T, int Rows, int Cols, int Options, int MaxRows, int MaxCols>
auto format_as(const Matrix<T, Rows, Cols, Options, MaxRows, MaxCols>& matrix)
{
    std::stringstream ss{};
    ss << matrix;
    return ss.str();
}

auto format_as(const MatrixXd& matrix)
{
    std::stringstream ss{};
    ss << matrix;
    return ss.str();
}

} // namespace Eigen


template<typename T>
T get_value(const nlohmann::json& j, const std::string& key)
{
    if (j.contains(key)) {
        return j[key].template get<T>();
    } else {
        throw std::runtime_error("Key not found in JSON object.");
    }
}

int main(int argc, char* argv[])
{
    using namespace Eigen;
    using json = nlohmann::json;
    auto m = Eigen::MatrixXd::Random(3, 3);
    fmt::print("Matrix:\n{}\n", m);

    std::fstream file{ "example.json" };
    auto data = json::parse(file);
    fmt::println("pi: {}", get_value<double>(data, "pi"));

    return EXIT_SUCCESS;
}
