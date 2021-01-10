import java.math.BigDecimal;
import java.util.Scanner;

public class HDU5927 {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigDecimal two,three,five,a,b;
        two = BigDecimal.valueOf(2);
        three = BigDecimal.valueOf(3);
        five = BigDecimal.valueOf(5);
        //二分法求sqrt(5)
        BigDecimal l = two, r = three;
        for(int i = 0; i < 500; i ++){
            BigDecimal mid = l.add(r).divide(two);
            if(mid.multiply(mid).compareTo(five) < 0)
                l = mid; //右移
            else
                r = mid; //左移
        }
        BigDecimal gold = l.add(BigDecimal.ONE).divide(two);//威佐夫博弈黄金分割率
        while(in.hasNext()){
            a = in.nextBigDecimal();
            b = in.nextBigDecimal();
            if(a.compareTo(b) < 0){//a>b
                BigDecimal temp = a;
                a = b;
                b = temp;
            }
            BigDecimal temp = a.subtract(b);
            temp = temp.multiply(gold);
            temp = temp.setScale(0, BigDecimal.ROUND_FLOOR);//向下取整
            if(temp.compareTo(b) == 0)
                System.out.println("0");
            else
                System.out.println("1");
        }
    }

}
