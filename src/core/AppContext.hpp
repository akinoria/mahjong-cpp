#pragma once // ヘッダの多重インクルード防止
#include <string>

// C++のどこからでもデータパスを設定・取得できるようにする

// データファイルのパスを設定する関数
void initialize_data_path(const std::string &path);

// 設定されたデータファイルのパスを取得する関数
const std::string &get_data_path();