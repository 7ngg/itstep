import { Text, View } from "react-native";
import "@/src/globals.css";
import Button from "../shared/ui/button";
import { router, SplashScreen } from "expo-router";
import Ionicons from "@expo/vector-icons/Ionicons";
import { useFonts } from "expo-font";
import { useEffect } from "react";
import HomeIcon from "./icon";

export default function App() {
  const [loaded, error] = useFonts({
    "Jakarta-Regular": require("@/assets/PlusJakartaSans-Regular.ttf"),
    "Jakarta-Bold": require("@/assets/PlusJakartaSans-Bold.ttf"),
    "Jakarta-ExtraBold": require("@/assets/PlusJakartaSans-ExtraBold.ttf"),
  });

  useEffect(() => {
    if (!loaded) {
      SplashScreen.hideAsync();
    }
  }, [loaded, error]);

  if (!loaded && !error) return null;

  return (
    <View className="flex items-center justify-between flex-1 gap-4 p-4">
      <View className="w-full flex items-center">
        <HomeIcon />
        <Text
          className="text-center"
          style={{ fontFamily: "Jakarta-ExtraBold", fontSize: 50 }}
        >
          Giris etmeyin vaxti geldi
        </Text>
      </View>
      <View className="w-full flex items-center gap-6">
        <View className="flex-row items-center gap-3">
          <Ionicons name="logo-google" size={30} />
          <Text style={{ fontFamily: "Jakarta-Regular" }}>
            Google ile davam et
          </Text>
        </View>
        <View className="flex-row items-center gap-4">
          <View className="flex-1 h-[1px] bg-gray-200" />
          <Text className="text-gray-700">ve ya</Text>
          <View className="flex-1 h-[1px] bg-gray-200" />
        </View>
        <Button>
          <Text className="text-white font-bold">Istifadeci kimi davam et</Text>
        </Button>
        <Button>
          <Text className="text-white font-bold">
            Barber kimi qeydiyyatdan kec
          </Text>
        </Button>
      </View>
      <View>
        <Text className="text-[#cfcfcf]">
          Hesabiniz yoxdur?{" "}
          <Text
            className="text-[#fb9401] font-bold"
            style={{ fontFamily: "Jakarta-Bold" }}
            onPress={() =>
              router.push({ pathname: "/auth", params: { type: "sign-up" } })
            }
          >
            Qeydiyyatdan kec
          </Text>
        </Text>
      </View>
    </View>
  );
}
