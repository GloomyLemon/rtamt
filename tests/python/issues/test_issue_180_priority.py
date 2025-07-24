import unittest
from rtamt import StlDenseTimeSpecification


class TestIssue180(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestIssue180, self).__init__(*args, **kwargs)

    def test_issue_180_1(self):
        spec1 = StlDenseTimeSpecification()
        spec1.spec = "firstTerm - 10 + 10"
        spec1.declare_var("firstTerm", "float")
        spec1.parse()

        spec2 = StlDenseTimeSpecification()
        spec2.spec = "firstTerm / 10 * 10"
        spec2.declare_var("firstTerm", "float")
        spec2.parse()

        rob1 = spec1.update(['firstTerm', [(0, 25), (10, 75), (20, 100)]])
        result1 = [[0, 25], [10, 75], [20, 100]]
        print('spec1: ' + str(rob1))

        rob2 = spec2.update(['firstTerm', [(0, 50), (10, 200), (20, 1000)]])
        result2 = [[0, 50], [10, 200], [20, 1000]]
        print('spec2: ' + str(rob2))

        self.assertListEqual(rob1, result1)
        self.assertListEqual(rob2, result2)

if __name__ == '__main__':
    unittest.main()