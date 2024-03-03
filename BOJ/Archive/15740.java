import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        try (InputStreamReader isr = new InputStreamReader(System.in)) {
            try (BufferedReader reader = new BufferedReader(isr)) {
                String input = reader.readLine();
                BigInteger.processInput(input);
            }
        }
    }
}

class BigInteger  {
    public static final String QUIT_COMMAND = "quit";

    boolean sign;   // integer is positive if sign is true
    byte[] num;     // digit numbers of integer

    public BigInteger(String s, boolean sgn) {
        num = new byte[s.length()];
        for(int i = 0; i < s.length(); i++) {
            num[i] = (byte)(s.charAt(i) - '0');
        }
        sign = sgn;
    }

    public BigInteger(byte[] s, boolean sgn) {
        num = s;
        sign = sgn;
    }

    public BigInteger add(BigInteger tar) {
        int len = Math.max(num.length, tar.num.length);
        byte[] res = new byte[len+1];

        for(int i = 0; i < len; i++) {
            if(i < num.length) {
                if (sign) res[i] += num[i];
                else res[i] -= num[i];
            }
            if(i < tar.num.length) {
                if (tar.sign) res[i] += tar.num[i];
                else res[i] -= tar.num[i];
            }
            if(res[i] > 9) res[i+1]++;
            if(res[i] < 0) res[i+1] += (res[i] - 9) / 10;
            res[i] -= 10 * res[i+1];
        }

        if(res[len] >= 0) return new BigInteger(res, true);

        for(int i = 0; i < len; i++) {
            if(res[i] > 0) {
                res[i+1]++;
                res[i] = (byte)(10 - res[i]);
            }
        }
        res[len] *= -1;
        return new BigInteger(res, false);
    }


    public BigInteger multiply(BigInteger tar) {
        int len = num.length + tar.num.length;
        byte[] res = new byte[len];
        for(int i = 0; i < num.length; i++) {
            for(int j = 0; j < tar.num.length; j++) {
                res[i+j] += num[i] * tar.num[j];
                res[i+j+1] += res[i+j] / 10;
                res[i+j] %= 10;
            }
        }
        for(int i = 0; i + 1 < len; i++) {
            res[i+1] += res[i] / 10;
            res[i] %= 10;
        }
        return new BigInteger(res, sign == tar.sign);
    }

    @Override
    public String toString() {
        StringBuilder ret = new StringBuilder();
        if(!sign) ret.append('-');
        boolean flag = false;
        for(int i = num.length - 1; i >= 0; i--) {
            if(!flag && num[i] != 0) flag = true;
            if(flag) ret.append(num[i]);
        }
        if(!flag) return "0";
        else return ret.toString();
    }

    static class StrIter {
        String str;
        int p;

        StrIter(String s, int value) {
            str = s;
            p = value;
        }
        private void next() { p++; }
        private boolean valid() { return p < str.length(); }
        private char get() { return str.charAt(p); }

        boolean getSign() throws IllegalArgumentException {
            while(valid() && get() == ' ') next(); // skip blanks
            if(!valid()) throw new IllegalArgumentException("Integer Not Found");
            if(get() == '-') {
                next();
                return false;
            }
            if(get() == '+') next();
            return true;
        }

        String getNum() throws IllegalArgumentException {
            StringBuilder arg = new StringBuilder();
            while(valid() && get() == ' ') next(); // skip blanks
            while(valid() && get() >= '0' && get() <= '9') {
                arg.append(get());
                next();
            }
            if(arg.length() == 0) throw new IllegalArgumentException("Integer Not Found");
            arg.reverse();
            return arg.toString();
        }

        int getOperator() throws IllegalArgumentException {
            int ret;
            while(valid() && get() == ' ') next(); // skip blanks
            if(!valid()) throw new IllegalArgumentException("Operator Not Found");
            if(get() == '+') ret = 0;
            else if(get() == '-') ret = 1;
            else if(get() == '*') ret = 2;
            else throw new IllegalArgumentException("Unexpected Operator Found");
            next();
            return ret;
        }

        void end() throws IllegalArgumentException {
            while(valid() && get() == ' ') next(); // skip blanks
            if(valid()) throw new IllegalArgumentException("Additional Illegal Argument Found");
        }
    }

    static BigInteger evaluate(String input) throws IllegalArgumentException {
        StrIter tar = new StrIter(input, 0);
        boolean sign1, sign2;
        String arg1, arg2;
        int op = 0;

        sign1 = tar.getSign();
        arg1 = tar.getNum();
        //op = tar.getOperator();
        sign2 = tar.getSign();
        arg2 = tar.getNum();
        tar.end();

        if(op == 1) {
            sign2 = !sign2;
            op = 0;
        }

        BigInteger num1 = new BigInteger(arg1, sign1);
        BigInteger num2 = new BigInteger(arg2, sign2);
        if(op == 0) return num1.add(num2);
        else return num1.multiply(num2);
    }

    static boolean processInput(String input) throws IllegalArgumentException {
        boolean quit = isQuitCmd(input);

        if (quit) {
            return true;
        }
        else {
            BigInteger result = evaluate(input);
            System.out.println(result);

            return false;
        }
    }

    static boolean isQuitCmd(String input) {
        return input.equalsIgnoreCase(QUIT_COMMAND);
    }
}
