import re

with open('data.txt', 'r') as f:
    matches_by_card = [(0, [])]
    for idx, card in enumerate(f.read().split('\n'), 1):
        nums = re.findall(r'\d+', card)
        winners = {int(i) for i in nums[1:11]}
        scratch = {int(i) for i in nums[11:]}
        matches = len(winners & scratch)
        new_cards = list(range(idx + 1, idx + matches + 1)) if matches else []
        matches_by_card.append((matches, new_cards))

def AOC_2023_day4_pt1():
    total = 0
    for matches, _ in matches_by_card:
        if matches:
            total += 2**(matches - 1)
    return total

def AOC_2023_day4_pt2():
    total = 0
    cards = list(range(1, len(matches_by_card)))
    while cards:
        total += len(cards)
        new_cards = []
        for num in cards:
            new_cards += matches_by_card[num][1]
        cards = new_cards[:]
    return total

print(AOC_2023_day4_pt1())
print(AOC_2023_day4_pt2())