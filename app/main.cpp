#include <Eigen/Eigen>
#include <fmt/base.h>
#include <fmt/format.h>

#include <cstdlib>
#include <iostream>
#include <sstream>

namespace Eigen {

auto format_as(const Matrix2d& matrix)
{
    std::stringstream ss{};
    ss << matrix;
    return ss.str();
}

} // namespace Eigen

int main(int argc, char* argv[])
{
    Eigen::Matrix2d m;
    m << 1, 2, 3, 4;

    fmt::println("{}", m);

    std::cout << m << '\n';

    std::stringstream ss{};
    ss << m;

    std::cout << ss.str() << '\n';

    return EXIT_SUCCESS;
}
