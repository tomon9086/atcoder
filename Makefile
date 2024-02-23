# デフォルトのターゲットを設定
.DEFAULT_GOAL := all

# コンパイラの設定
CXX := clang++

# コンパイルオプションの設定
CXXFLAGS := -std=c++11 -Wall -Wextra

# 変数
CONTEST_ID := $(c)
PROBLEM_NUMBER := $(q)

# ファイル名の設定
SRC := $(CONTEST_ID)/$(PROBLEM_NUMBER).cpp
OUT := $(CONTEST_ID)/$(PROBLEM_NUMBER).out

# ターゲットを作成
.PHONY: all
all: check_vars $(OUT) run

# 問題番号とファイル名が空でないことをチェックするルール
.PHONY: check_vars
check_vars:
	@if [ -z "$(CONTEST_ID)" ]; then \
		echo "ERROR: c is not defined. Please specify the contest ID."; \
		exit 1; \
	fi
	@if [ -z "$(PROBLEM_NUMBER)" ]; then \
		echo "ERROR: q is not defined. Please specify the file name."; \
		exit 1; \
	fi

# a.outを作成するルール
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

# a.outを実行するルール
.PHONY: run
run: $(OUT)
	./$(OUT)

# cleanターゲットを作成
.PHONY: clean
clean:
	rm -f $(OUT)
