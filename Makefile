# デフォルトのターゲットを設定
.DEFAULT_GOAL := all

# コンパイラの設定
CXX := g++

# コンパイルオプションの設定
CXXFLAGS := -std=c++20 -Wall -Wextra

# 変数
CONTEST_ID := $(c)
PROBLEM_NUMBER := $(q)

# テンプレートファイル名の設定
TEMPLATE_HELLO_WORLD := templates/cpp/helloworld.cpp

# テストファイルディレクトリの設定
TESTS_DIR := tests
PROBLEM_TEST_DIR=$(TESTS_DIR)/$(CONTEST_ID)/$(PROBLEM_NUMBER)
MAX_TEST_NUMBER := $(shell ls -1 $(PROBLEM_TEST_DIR)/*.txt 2>/dev/null | awk -F/ '{print $$NF}' | awk -F. '{print $$1}' | sort -n | tail -n 1)
NEXT_TEST_NUMBER := $(shell echo $$(($(MAX_TEST_NUMBER) + 1)))
PROBLEM_TEST_FILES := $(wildcard $(PROBLEM_TEST_DIR)/*.txt)

# ファイル名の設定
SRC := src/$(CONTEST_ID)/$(PROBLEM_NUMBER).cpp
OUT := src/$(CONTEST_ID)/$(PROBLEM_NUMBER).out

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

# ファイルを作成するルール
.PHONY: new
new: check_vars
	mkdir -p $(CONTEST_ID)
	cp $(TEMPLATE_HELLO_WORLD) $(SRC)

# テストファイルを作成するルール
.PHONY: test_new
test_new: check_vars
	mkdir -p $(PROBLEM_TEST_DIR)
	touch $(PROBLEM_TEST_DIR)/$(NEXT_TEST_NUMBER).txt
	@echo "Created file $(NEXT_TEST_NUMBER).txt"

# a.outを作成するルール
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

# a.outを実行するルール
.PHONY: run
run: $(OUT)
	./$(OUT)

# 全テストファイルを実行するルール
.PHONY: test
test: check_vars $(OUT) $(PROBLEM_TEST_FILES:%.txt=%_run)

# 各テストファイルを実行するルール
$(PROBLEM_TEST_DIR)/%_run: $(PROBLEM_TEST_DIR)/%.txt
	@echo "Running $<:"
	@./$(OUT) <$<

# cleanターゲットを作成
.PHONY: clean
clean:
	rm -f $(OUT)
