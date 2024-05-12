# tmquan-findthetreasure
README.txt
**Các file cần cài**
- game_draw.h
- open_the_treasure.h
- game_test.cpp

**Tiếng Việt**
Màn 1: mục tiêu của bạn là cho nhân vật di chuyển trên con đường gồm 20 ô để tìm kho báu ở vạch đích. Bạn sẽ có 10 lượt tung xúc xắc, số điểm nhận được là số ô mà nhân vật sẽ di chuyển. Sẽ có chướng ngại vật hoặc vật phẩm trên đường.
Ký hiệu:
‘o’ nhân vật
‘U’ bẫy – khi nhân vật dẫm phải bẫy, số lượt của bạn bị trừ đi 2
‘$’ vật phẩm – có thể sử dụng để bỏ qua một chướng ngại vật, khi sử dụng sẽ tự động tung xúc xắc lần tiếp theo
‘3’ nhân vật lùi 3 bước
‘!’ nhân vật trở lại ô 1 (nếu sử dụng vật phẩm mà lần tung xúc sắc tự động tiếp theo không đưa nhân vật về đích thì sẽ trở về ô 1)
‘X’ kho báu – khi nhận được sẽ chuyển sang màn 2.

Màn 2: mục tiêu của bạn là đoán số tự nhiên từ 1 đến 99 được tạo bất kỳ, nếu đoán đúng sẽ mở được kho báu. Bạn có thể nhấn 1 để đoán số, nhấn 2 để lấy gợi ý về con số, nhấn 3 để thoát trò chơi. Mỗi lần đoán hoặc lấy gợi ý sẽ tiêu tốn 1 lượt. Bạn sẽ có 8 lượt để đoán.

**English:**
Stage 1: Your goal is to make the character move on a path of 20 steps to find the treasure at the finish line. You will have 10 turns to roll the dice, the number of points received is the number of steps the character will move. There will be obstacles or items on the way.
Symbol:
'o' your character
‘U’ trap – when the character steps on thí trap, your turn count is reduced by 2
‘$’ item – can be used to bypass an obstacle, when used will automatically roll the next dice
‘3’ the character takes 3 steps back
‘!’ the character returns to step 1 (if using an item and the next automatic dice roll does not bring the character to the finish line, the character will return to step 1)
‘X’ treasure – when received, it will move to stage 2.

Stage 2: Your goal is to guess a generated natural number from 1 to 99. If you guess correctly, you will open the treasure. You can press 1 to guess the number, press 2 to get a hint about the number, press 3 to exit the game. Each guess or hint will consume 1 turn. You will have 8 turns to guess.

