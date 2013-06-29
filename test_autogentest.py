
import unittest
import autogentest as agt

class TestCases(unittest.TestCase):

    @unittest.expectedFailure
    def test_ABCctor(self):
        a = agt.A()

        
    def test_overloads(self):
        b = agt.B()
        b.overloadedMethod()
        b.overloadedMethod(1, 2)
        b.overloadedMethod(1.23)
        b.overloadedMethod(1)


    @unittest.expectedFailure
    def test_tooManyArgs(self):
        b = agt.B()
        b.overloadedMethod(1, 2, 3)


    def test_defaultArgs(self):
        b = agt.B()
        b.defaultArgs()
        b.defaultArgs(1)
        b.defaultArgs(1, 2)

        
    def test_keywordArgs(self):
        b = agt.B()
        b.defaultArgs()
        b.defaultArgs(a=5, b=6)
        b.defaultArgs(b=5, a=6)
        b.defaultArgs(b=6)
                        
                        
    def test_isinstance(self):
        b = agt.B()
        c = agt.C()
        
        assert isinstance(b, agt.B)
        assert isinstance(b, agt.A)
        assert isinstance(c, agt.C)
        assert isinstance(c, agt.B)
        assert isinstance(c, agt.A)
        


if __name__ == '__main__':
    unittest.main()