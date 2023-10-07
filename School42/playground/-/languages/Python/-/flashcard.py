class Flashcard:
    def __init__(self, question, answer):
        self.question = question
        self.answer = answer


class Flashcards:
    def __init__(self):
        self.cards = []

    def create_flashcard(self, question, answer):
        self.cards.append(Flashcard(question, answer))

    def view_flashcards(self):
        for i, card in enumerate(self.cards):
            print(f'Card {i+1}:')
            print(f'Question: {card.question}')
            print(f'Answer: {card.answer}\n')

    def edit_flashcard(self, card_number, question, answer):
        self.cards[card_number-1].question = question
        self.cards[card_number-1].answer = answer

    def delete_flashcard(self, card_number):
        del self.cards[card_number-1]

    def study_flashcards(self):
        for card in self.cards:
            print(f'Question: {card.question}')
            input('Press enter to see the answer')
            print(f'Answer: {card.answer}\n')
