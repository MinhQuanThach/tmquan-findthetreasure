**Các file cần cài**

- game_draw.h
- open_the_treasure.h
- game_test.cpp
  
**Tiếng Việt**
- Màn 1: mục tiêu của bạn là cho nhân vật di chuyển trên con đường gồm 20 ô để tìm kho báu ở vạch đích. Bạn sẽ có 10 lượt tung xúc xắc, số điểm nhận được là số ô mà nhân vật sẽ di chuyển. Sẽ có chướng ngại vật hoặc vật phẩm trên đường. Ký hiệu:
+ ‘o’ nhân vật
+ ‘U’ bẫy – khi nhân vật dẫm phải bẫy, số lượt của bạn bị trừ đi 2
+ ‘$’ vật phẩm – có thể sử dụng để bỏ qua một chướng ngại vật, khi sử dụng sẽ tự động tung xúc xắc lần tiếp theo
+ ‘3’ nhân vật lùi 3 bước
+ ‘!’ nhân vật trở lại ô 1 (nếu sử dụng vật phẩm mà lần tung xúc sắc tự động tiếp theo không đưa nhân vật về đích thì sẽ trở về ô 1)
+ ‘X’ kho báu – khi nhận được sẽ chuyển sang màn 2.
- Màn 2: mục tiêu của bạn là đoán số tự nhiên từ 1 đến 99 được tạo bất kỳ, nếu đoán đúng sẽ mở được kho báu. Bạn có thể nhấn 1 để đoán số, nhấn 2 để lấy gợi ý về con số, nhấn 3 để thoát trò chơi. Mỗi lần đoán hoặc lấy gợi ý sẽ tiêu tốn 1 lượt. Bạn sẽ có 8 lượt để đoán.

**Tài liệu tham khảo**
https://lazyfoo.net/tutorials/SDL/
https://tailieuvnu.com/giao-trinh-lap-trinh-nang-cao-nguyen-van-vinh-pham-quoc-thai-tran-quoc-long-uet/
