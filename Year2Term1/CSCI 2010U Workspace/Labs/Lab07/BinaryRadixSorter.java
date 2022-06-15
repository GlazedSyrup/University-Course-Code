public class BinaryRadixSorter {
public static String[] altList = new String[5];

    public static String toString(String[] numbers) {
        String result = "[ ";
        for(int i = 0; i < numbers.length; i++){
            result += numbers[i] + " ";
        }
        return result += "]";
    }

    public static String[] sort(int numDigits, String[] numbers) {
        for(int i = 0; i < numbers.length; i++){
            altList[i] = numbers[i];
        }
        System.out.println("Sorting:");
        for(int i = 3; i >= 0; i--){
            System.out.println(toString(numbers));
            sortDigit(i, numbers);
        }
        System.out.println(toString(numbers));
        return numbers;
    }
    
    public static void sortDigit(int digitIndex, String[] numbers) {
        int lastI = 0;
        for(int i = 0; i < numbers.length; i++){
            if(numbers[i].charAt(digitIndex) == '0'){
                altList[lastI] = numbers[i];
                lastI += 1;
            }
        }
        for(int i = 0; i < numbers.length; i++){
            if(numbers[i].charAt(digitIndex) == '1'){
                altList[lastI] = numbers[i];
                lastI += 1;
            }
        }
        for(int i = 0; i < numbers.length; i++){
            numbers[i] = altList[i];
        }

    }
    
}