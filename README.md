# 과제 내용 정리
 - 에디터가 실행되면 GameMode를 통해 MyActor가 에디터에 spawn 됩니다.  
이후 10번의 step() 함수가 발생되어 x,y좌표에 1또는 0을 랜덤하게 반환하며
해당 값 만큼 이동합니다.  
해당 step()함수 발생 시 마다 event를 50% 확률로 발생시키며, xy좌표값을 계산하여 좌표상 이동거리인 distance 또한 표시합니다.  
최종 10번의 step() 이후 step횟수, 현재 location, total distance, event 발생 횟수 등을 표시합니다.  
---
## 2025-09-03
- Event 및 Distance 추가
---
## 2025-09-02
- Myactor / step, move 구현
- 프로젝트 생성
