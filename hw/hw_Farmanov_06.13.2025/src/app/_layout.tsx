import { router, Stack } from "expo-router";
import { View } from "react-native";
import "@/src/globals.css";
import Ionicons from "@expo/vector-icons/Ionicons";
import { SafeAreaView } from "react-native-safe-area-context";

export default function RootLayout() {
  return (
    <SafeAreaView className="flex-1 p-4">
      <View className="flex items-start w-full">
        <Ionicons name="arrow-back" size={25} onPress={router.back}/>
      </View>
      <Stack screenOptions={{ headerShown: false }} />
    </SafeAreaView>
  );
}
