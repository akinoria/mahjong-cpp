#include "table.hpp"

#include <boost/dll.hpp>
#include <boost/filesystem.hpp>

namespace mahjong
{

/**
 * @brief Initialize the table.
 *
 * @return Returns true if initialization is successful, otherwise false.
 */
bool Table::initialize(const std::string &data_path)
{
    boost::filesystem::path path(data_path);
#ifdef USE_NYANTEN_TABLE
    boost::filesystem::path suits_table_path = path / "suits_table_nyanten.bin";
    boost::filesystem::path honors_table_path = path / "honors_table_nyanten.bin";
#else
    boost::filesystem::path suits_table_path = path / "suits_table.bin";
    boost::filesystem::path honors_table_path = path / "honors_table.bin";
#endif

    return load_table(suits_table_path.string(), suits_table_) &&
           load_table(honors_table_path.string(), honors_table_);
}

std::array<Table::TableType, Table::SuitsTableSize> Table::suits_table_;
std::array<Table::TableType, Table::HonorsTableSize> Table::honors_table_;

} // namespace mahjong
