#include "AppContext.hpp"
#include "mahjong/core/expected_score_calculator.hpp"
#include "mahjong/core/table.hpp"

namespace
{
// このファイル内でのみアクセス可能な変数としてパスを保持する
std::string g_data_path = ".";
} // namespace

void initialize_data_path(const std::string &path)
{
    g_data_path = path;
    mahjong::Table::get_instance().initialize(path);
    mahjong::ExpectedScoreCalculator::load_uradora_table(path);
}

const std::string &get_data_path()
{
    return g_data_path;
}