# 컴파일러 지정
CC = g++

# 컴파일 옵션
# -Iheader 헤더 파일이 위치한 디렉토리를 지정한다.
# -Wall 모든 경고 메시지를 활성화 한다.
# -Wextra 추가적인 경고 멧시지를 활성화 한다.
# -std=c++11 C++11 표준을 사용한다.
CFLAGS = -Iheader -Wall -Wextra -std=c++11

# 소스 파일 디렉토리
SRCDIR = source

# 헤더 파일 디렉토리
INCDIR = header

# 대상 파일 디렉토리
OBJDIR = obj

# 실행 파일
TARGET = OOP_Project_04

# 소스 파일 목록
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# 객체 파일 목록
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# 기본 규칙
all: $(TARGET)

# 실행 파일 생성 규칙
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# 객체 파일 생성 규칙
# /% -> 패턴 규칙으로 지정된 디렉토리에 있는(OBJDIR,SRCDIR) 모든 확장자(.o,.cpp) 파일을 의미한다.
# $< -> 현재 규칙의 첫 번째 의존 파일을 나타낸다. 
# $@ -> 규칙의 타겟 파일을 나타낸다.
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 객체 파일 디렉토리 생성 규칙
$(OBJDIR):
	mkdir -p $(OBJDIR)

# 청소 규칙
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean