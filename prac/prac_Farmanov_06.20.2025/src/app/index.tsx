import Button from "../shared/ui/button";
import "./index.css"
import { Text, View } from "react-native";
import { useFonts } from "expo-font"
import { useEffect } from "react";
import { SplashScreen } from "expo-router";
import Intro from "../pages/intro";
import { SafeAreaView } from "react-native-safe-area-context";

export default function App() {
  const [loaded, error] = useFonts({
    'Jakarta-Regular': require("@/assets/fonts/PlusJakartaSans-Regular.ttf"),
    'Jakarta-Bold': require("@/assets/fonts/PlusJakartaSans-Bold.ttf")
  })

  useEffect(() => {
    if (loaded || error) {
      SplashScreen.hideAsync()
    }
  }, [loaded, error])

  return (
    <SafeAreaView className="flex-1 items-center bg-white">
      <View className="h-full">
        <Intro />
      </View>
    </SafeAreaView>
  );
}
