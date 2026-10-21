class Solution {
public: // alars de armas ...
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
      
        if (hand.size() % groupSize != 0) {
            return false;
        }

    
        map<int, int> cardCounts;
        for (int card : hand) {
            cardCounts[card]++;
        }

      
        for (auto it = cardCounts.begin(); it != cardCounts.end(); ++it) {
            int currentCard = it->first;
            int count = it->second;

           
            if (count == 0) {
                continue;
            }

         
            for (int i = 0; i < groupSize; ++i) {
                int nextCard = currentCard + i;

               
                if (cardCounts[nextCard] < count) {
                    return false;
                }

            
                cardCounts[nextCard] -= count;
            }
        }

        return true;
    }
};