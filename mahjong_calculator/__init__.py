import pathlib
from . import _mahjong_calculator

# この__init__.pyファイルがあるディレクトリを取得
_package_dir = pathlib.Path(__file__).resolve().parent

# データファイルが格納されているディレクトリへのパスを構築
# MANIFEST.inの設定に基づき、データは'data/config'にコピーされる想定
_data_path = _package_dir / "data"

# C++モジュールにデータパスを渡して初期化
_mahjong_calculator.initialize(str(_data_path))

# C++モジュールの関数をトップレベルに公開
create_response = _mahjong_calculator.create_response

# __all__ を定義して、from mahjong_calculator import * で何をインポートするかを明示
__all__ = ["create_response"]