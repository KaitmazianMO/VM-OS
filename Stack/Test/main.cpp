#include <gtest/gtest.h>
#include <utility> 

#include "../StackLib/Stack_impl.hpp"

class StackTest : public ::testing::Test {
public:
    template <typename T>
    T ComputeDiscriminantByStack(T a, T b, T c) {
        Stack<T> stk;
        stk.push(b);
        stk.push(b);
        double l = stk.top();
        stk.pop();
        double r = stk.top();
        stk.pop();
        stk.push(l*r); // b*b at the top

        stk.push(a);
        stk.push(c);
        l = stk.top();
        stk.pop();
        r = stk.top();
        stk.pop();   
        stk.push(l*r); // a*c at the top

        stk.push(4);
        l = stk.top();
        stk.pop();
        r = stk.top();
        stk.pop();  
        stk.push(l*r); // 4*a*c at the top

        l = stk.top();
        stk.pop();
        r = stk.top();
        stk.pop();  
        stk.push(r - l); // (b*b - 4*a*c) at the top
        
        return stk.top();
    }

    template <typename T>
    std::pair<T, T> DiscriminantByFormulaAndByStack(T a, T b, T c) {
        return std::make_pair<T, T>(b*b - 4*a*c, ComputeDiscriminantByStack (a, b, c));
    }
};

TEST_F(StackTest, PushTop) {
    Stack<int> stk_int;
    Stack<double> stk_double;
    Stack<bool> stk_bool;

    stk_int.push(42);
    ASSERT_EQ(42, stk_int.top());
    
    stk_double.push(1.41);
    ASSERT_DOUBLE_EQ(1.41, stk_double.top());
    
    stk_bool.push(true);
    ASSERT_EQ(true, stk_bool.top());
}

TEST_F(StackTest, EmptyStackPop) {
    {
        Stack<int> stk_int;
        Stack<double> stk_double;
        Stack<bool> stk_bool;
        
        ASSERT_DEATH({stk_int.pop();}, ""); 
        ASSERT_DEATH({stk_double.pop();}, ""); 
        ASSERT_DEATH({stk_bool.pop();}, ""); 
    }
    {
        Stack<int> stk_int;
        Stack<double> stk_double;
        Stack<bool> stk_bool;
        
        stk_int.push(1);
        stk_double.push(1);
        stk_bool.push(1);
        stk_int.pop();
        stk_double.pop();
        stk_bool.pop();
    
        ASSERT_DEATH({stk_int.pop();}, ""); 
        ASSERT_DEATH({stk_double.pop();}, ""); 
        ASSERT_DEATH({stk_bool.pop();}, "");
    }     
}

TEST_F(StackTest, EmptyStackTop) {
    Stack<int> stk_int;
    Stack<double> stk_double;
    Stack<bool> stk_bool;
    
    ASSERT_DEATH({stk_int.top();}, ""); 
    ASSERT_DEATH({stk_double.top();}, ""); 
    ASSERT_DEATH({stk_bool.top();}, ""); 
}

TEST_F(StackTest, ComputeDiscriminant) {
    auto discr_pair = DiscriminantByFormulaAndByStack<double>(__LINE__, 2*__LINE__, __LINE__);
    ASSERT_DOUBLE_EQ(discr_pair.first, discr_pair.second);     

    discr_pair = DiscriminantByFormulaAndByStack<double>(5*__LINE__, 2*__LINE__, 9*__LINE__);
    ASSERT_DOUBLE_EQ(discr_pair.first, discr_pair.second); 
    
    discr_pair = DiscriminantByFormulaAndByStack<double>(__LINE__*__LINE__, 99*__LINE__, -55*__LINE__);
    ASSERT_DOUBLE_EQ(discr_pair.first, discr_pair.second);          
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}