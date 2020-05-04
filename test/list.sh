((0)) && echo a
((1)) && echo aa
((0)) || echo d
((0)) && ((0))
((0)) && ((0)) || echo dd
((1)) && ((2)) && echo b || echo bb
((1)) && ((0)) && echo c || echo cc