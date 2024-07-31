def ask_question(question):
    while True:
        response = input(f"{question} (y/n): ").strip().lower()
        if response in ('y', 'n'):
            return response == 'y'
        print("Please answer with 'y' or 'n'.")

def main():
    print("Welcome to the 21 Questions game!")
    print("Think of something, and I'll try to guess what it is by asking up to 21 yes/no questions.")

    question_number = 1

    while question_number <= 21:
        if question_number == 1:
            answer = ask_question("Is it something that is alive?")
            if answer:
                answer = ask_question("Is it an animal?")
                if answer:
                    answer = ask_question("Does it live in the water?")
                    if answer:
                        print("It sounds like you're thinking of a fish!")
                        break
                    else:
                        answer = ask_question("Is it a common pet?")
                        if answer:
                            print("It sounds like you're thinking of a dog!")
                            break
                        else:
                            print("It sounds like you're thinking of a wild animal!")
                            break
                else:
                    print("It sounds like you're thinking of a plant or something else living!")
                    break
            else:
                answer = ask_question("Is it something that can be found indoors?")
                if answer:
                    print("It sounds like you're thinking of an appliance or piece of furniture!")
                    break
                else:
                    print("It sounds like you're thinking of something found outdoors!")
                    break

        # You can add more questions and logic here as needed

        question_number += 1

    if question_number > 21:
        print("I reached the maximum number of questions. I couldn't guess what you're thinking of.")

if __name__ == "__main__":
    main()
