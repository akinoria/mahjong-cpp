#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <stdexcept>
#include <string>

// [修正] AppContext.hpp をインクルードして、共有機能を使えるようにする
#include "core/AppContext.hpp"
#include "mahjong/mahjong.hpp"
#include "server/json_parser.hpp"

// CMakeなどのビルドシステムで定義されていない場合に備え、
// デフォルトのバージョンを定義しておきます。
#ifndef PROJECT_VERSION
#define PROJECT_VERSION "0.0.0"
#endif

namespace py = pybind11;

/**
 * @brief PythonからのJSONリクエストを処理し、JSONレスポンスを返すラッパー関数。
 * (この関数の中身に変更はありません)
 */
std::string create_response_wrapper(const std::string &json_request)
{
    try {
        // 1. JSON文字列をパース・検証
        rapidjson::Document doc;
        parse_json(json_request, doc);

        // 2. Requestオブジェクトを生成
        Request req = parse_request_doc(doc);

        // 3. 指定されたメイン関数を呼び出す
        rapidjson::Document res_doc = create_response(req);

        // 4. 結果をJSON文字列に変換して返す
        return to_json_str(res_doc);
    }
    catch (const std::exception &e) {
        // C++の例外をPythonのValueErrorに変換して送出
        throw py::value_error(e.what());
    }
}

// [追加] C++の initialize_data_path を呼び出すためのラッパー関数
void initialize_wrapper(const std::string &path)
{
    initialize_data_path(path);
}

PYBIND11_MODULE(_mahjong_calculator, m)
{
    m.doc() = "Python bindings for the C++ Mahjong Expected Score Calculator";

    m.def("create_response", &create_response_wrapper,
          "Takes a JSON request string and returns a JSON response string with mahjong "
          "analysis.",
          py::arg("json_request"));

    // [追加] initialize関数をPythonに公開する
    m.def("initialize", &initialize_wrapper,
          "Initializes the data path for C++ modules.", py::arg("path"));
}