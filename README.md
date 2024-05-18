실습과제1

labelex.png 영상파일(컬러영상)에서 레이블링을 수행

객체의 면적 최대, 최소를 찾고, 콘솔창에 정보를 출력

원본영상에 바운딩 박스 그리기

![KakaoTalk_20240519_003415665](https://github.com/sj714/opencv_ch12/assets/169256660/24ee4c44-f01b-4c9c-863b-366cec9130b5)

실습과제2

polygon.bmp 영상파일에서 레이블링을 수행

콘솔창에 label, x, y, width, height, area, color[B,G,R] 출력

원본영상에 바운딩 박스와 레이블값을 그리기

color는 무게중심 좌표에서 원본 영상의 컬러를 출력

![KakaoTalk_20240519_005940046](https://github.com/sj714/opencv_ch12/assets/169256660/34219279-3743-4165-b1b9-b365b73386d8)

실습과제3

polygon.bmp 영상파일에서 레이블링을 수행

각 객체의 무게중심을 직접 계산하여 콘솔창에 출력

![KakaoTalk_20240519_010808347](https://github.com/sj714/opencv_ch12/assets/169256660/030196e3-b2c1-433f-8f3c-55efd7fceae2)

실습과제4

원본영상(car.jpg)을 그레이로 변환

그레이 영상에서 블러링 적용하고, sobel 함수 이용하여 수직방향의 에지만 검출

에지 검출된 영상을 이진화하고, 닫기연산 수행

닫기연산시 구조요소행렬의 사이즈는 5행 32열로 가로방향으로 긴 사각형 형태의 마스크를 이용하여 숫자들을 하나의 객체로 합쳐준다.

번호판 영역을 검출하여 빨간색으로 표시

![KakaoTalk_20240519_013224257](https://github.com/sj714/opencv_ch12/assets/169256660/6d4a2645-9f33-4232-9365-74b9263aa531)

