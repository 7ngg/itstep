import Button from "@/src/shared/ui/button";
import { Text, View } from "react-native";

export default function Intro() {
  return (
    <View className="flex flex-col items-center justify-evenly h-full py-12 px-12">
      <View className="gap-3">
        <Text className="text-3xl font-[Jakarta-Bold] text-center">
          Your One-Stop Name Solution
        </Text>
        <Text className="text-gray-500 font-[Jakarta-Regular] text-lg text-center">
          Simplify the process of finding the perfect and professional name
        </Text>
      </View>
      <Button>
        <Text className="text-white text-xl font-[Jakarta-Regular]">Next</Text>
      </Button>
    </View>
  );
}
