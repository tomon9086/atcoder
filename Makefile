# デフォルトのターゲットを設定
.DEFAULT_GOAL := all

# コンパイラの設定
CXX := g++

# コンパイルオプションの設定
CXXFLAGS := -std=c++20 -Wall -Wextra

# 変数
CONTEST_ID := $(if $(c),$(c),$(shell grep -sE "^c=" .env | cut -d= -f2))
PROBLEM_NUMBER := $(if $(q),$(q),$(shell grep -sE "^q=" .env | cut -d= -f2))
TEST_FILES := $(t)

# テンプレートファイル名の設定
TEMPLATES_DIR := templates/cpp
TEMPLATE_COMMON_HEADER := $(TEMPLATES_DIR)/common/header.cpp
TEMPLATE_HELLO_WORLD_NAME := helloworld

# テストファイルディレクトリの設定
TESTS_DIR := tests
PROBLEM_TEST_DIR=$(TESTS_DIR)/$(CONTEST_ID)/$(PROBLEM_NUMBER)
MAX_TEST_NUMBER := $(shell ls -1 $(PROBLEM_TEST_DIR)/*.txt 2>/dev/null | awk -F/ '{print $$NF}' | awk -F. '{print $$1}' | sort -n | tail -n 1)
NEXT_TEST_NUMBER := $(shell echo $$(($(MAX_TEST_NUMBER) + 1)))
PROBLEM_TEST_FILES := $(wildcard $(PROBLEM_TEST_DIR)/*.txt)

# ファイル名の設定
SRC_DIR := src/$(CONTEST_ID)
SRC := $(SRC_DIR)/$(PROBLEM_NUMBER).cpp
OUT := $(SRC_DIR)/$(PROBLEM_NUMBER).out

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

# 環境変数を設定するルール
.PHONY: init
init:
	@if [ -f .env ] && [ -s .env ]; then \
		. .env; \
	fi; \
	read -p "Contest ID? (default: $$c): " contest_id; \
	read -p "Problem Number? (default: $$q): " problem_number; \
	c=$${contest_id:-$$c}; \
	q=$${problem_number:-$$q}; \
	echo "c=$$c" > .env; \
	echo "q=$$q" >> .env; \
	echo ""; \
	echo "Initialized!"; \
	echo "  Contest ID     : $$c"; \
	echo "  Problem Number : $$q"

# ファイルを作成するルール
.PHONY: new
new: new_$(TEMPLATE_HELLO_WORLD_NAME)

# ファイルを作成するルール
new_%: check_vars
	mkdir -p $(SRC_DIR)
	@if [ -e "$(SRC)" ]; then \
		read -p "File \"$(SRC)\" exists. Do you want to continue? (y/N): " choice; \
		case "$$choice" in \
			[yY]) ;; \
			*) echo "Aborted."; exit 1 ;; \
		esac; \
	fi
	cat $(TEMPLATE_COMMON_HEADER) $(TEMPLATES_DIR)/$(patsubst new_%,%,$@).txt > $(SRC)
	@echo ""
	@echo "Created source file $(SRC) !"

# テストファイルを作成するルール
.PHONY: new_test
new_test: check_vars
	mkdir -p $(PROBLEM_TEST_DIR)
	@if [ -t 0 ]; then \
		touch $(PROBLEM_TEST_DIR)/$(NEXT_TEST_NUMBER).txt; \
	else \
		cat > $(PROBLEM_TEST_DIR)/$(NEXT_TEST_NUMBER).txt; \
	fi
	@echo ""
	@echo "Created test file $(PROBLEM_TEST_DIR)/$(NEXT_TEST_NUMBER).txt !"

# a.outを作成するルール
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

# a.outを実行するルール
.PHONY: run
run: $(OUT)
	./$(OUT)

# 全テストファイルを実行するルール
.PHONY: test
test: check_vars $(OUT)
ifdef TEST_FILES
	@for file in $(TEST_FILES); do \
		if [ -f "$(PROBLEM_TEST_DIR)/$$file.txt" ]; then \
			$(MAKE) $(PROBLEM_TEST_DIR)/$$file\_run; \
		else \
			echo "File $$file.txt does not exist."; \
		fi; \
	done
else
	@for file in $(PROBLEM_TEST_FILES); do \
		$(MAKE) $${file%.*}_run; \
	done
endif

# 各テストファイルを実行するルール
$(PROBLEM_TEST_DIR)/%_run: $(PROBLEM_TEST_DIR)/%.txt
	@echo "Running $<:"
	@./$(OUT) <$<

# cleanターゲットを作成
.PHONY: clean
clean:
	rm -f $(OUT)
