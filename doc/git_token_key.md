- Git 이름 이메일 입력

  - 이메일 및 이메일이 정확하지 않다고 오류 발생이 존재하면 아래의 명령어로 이름 및 명령어를 등록한다.

  ~~~
  git config --global user.name "사용자이름"
  git config --global user.email "이메일@abc.com"
  ~~~

  ---

- Git 토큰 발급 방법

  1. github 접속
  2. 오른쪽 상단 내 아이콘을 클릭하여 `settings` 클릭
  3. 왼쪽 맨 아래 `Developer settings` 클릭
  4. `Personal access tokens` 클릭 ->  `Tokens (classic)` 클릭 
     GitHub API에 엑세스 할 수 있도록 생성되는 토큰 
  5. 오른쪽 상단의 첫번째 박스인 `Generate new token` 클릭 ->  `Generate new token (classic)` 클릭
     - Note: 마음대로 입력
     - Expiration: 만료일 설정
     - Select scopes: 토근 범위 체크 (확인하여 체크하면 된다.)
  6. 완료 되었으면 `Generate token` 클릭
  7. Git 접근할때 비밀번호 대신 생성된 토큰으로 접근 진행