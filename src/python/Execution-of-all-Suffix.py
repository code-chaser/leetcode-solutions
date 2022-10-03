 def executeInstructions(self, n, start, s):
        na = len(s)
        def test(i):
            res = 0
            x,y = start
            for j in xrange(i, na):
                o = s[j]
                if o == 'L': y -= 1
                if o == 'R': y += 1
                if o == 'U': x -= 1
                if o == 'D': x += 1
                if not (0 <= x < n and 0 <= y < n):
                    return j - i
            return na - i
        return map(test, range(na))
        
//By @KrishGaur1354
