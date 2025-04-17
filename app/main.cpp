#include <Eigen/Eigen>
#include <fmt/base.h>
#include <fmt/format.h>

#include <cstdlib>
#include <sstream>

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

int main(int argc, char* argv[])
{
    using namespace Eigen;
    auto m = Eigen::MatrixXd::Random(3, 3);
    fmt::print("Matrix:\n{}\n", m);

    return EXIT_SUCCESS;
}
