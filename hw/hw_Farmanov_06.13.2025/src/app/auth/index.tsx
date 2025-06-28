import Button from "@/src/shared/ui/button";
import Input from "@/src/shared/ui/input";
import Ionicons from "@expo/vector-icons/Ionicons";
import { View, Text } from "react-native";
import { SafeAreaView } from "react-native-safe-area-context";
import Checkbox from "expo-checkbox";
import { useMemo, useState } from "react";
import { router, useLocalSearchParams } from "expo-router";

export default function Auth() {
  const [isChecked, setIsChecked] = useState(false);
  const [email, setEmail] = useState<string>("");
  const [password, setPassword] = useState<string>("");

  const { type } = useLocalSearchParams();
  const isSignIn = type === "sign-in";

  const isValid = useMemo(() => {
    return email.length >= 3 && password.length >= 3;
  }, [email, password]);

  return (
    <SafeAreaView className="flex-1">
      <View className="p-4 gap-4 flex-1 justify-between">
        <View>
          <Text
            className="text-gray-700"
            style={{ fontFamily: "Jakarta-ExtraBold", fontSize: 50 }}
          >
            {isSignIn ? "Hesabina daxil ol" : "Oz barber hesabini yarat"}
          </Text>
        </View>
        <View className="gap-6">
          <Input
            icon={<Ionicons name="mail" size={20} color="gray" />}
            placeholder="Email"
            value={email}
            onChangeText={setEmail}
          />
          <Input
            icon={<Ionicons name="lock-closed" size={20} color="gray" />}
            placeholder="Password"
            secureTextEntry
            value={password}
            onChangeText={setPassword}
          />
          <View className="flex-row items-center gap-2">
            <Checkbox
              style={{ borderRadius: 6, borderColor: "#fb9401" }}
              value={isChecked}
              onValueChange={setIsChecked}
              color={isChecked ? "#fb9401" : undefined}
            />
            <Text className="font-[Jakarta-Bold] text-gray-700">
              Yadda saxla
            </Text>
          </View>
          <View className="items-center gap-4">
            <Button disabled={!isValid}>
              <Text className="font-[Jakarta-Bold] text-white">
                {isSignIn ? "Qeydiyyatdan kec" : "Daxil ol"}
              </Text>
            </Button>
            {isSignIn && (
              <Text className="text-[#fb9401] font-[Jakarta-Bold]">
                Sifreni unutmusan?
              </Text>
            )}
          </View>
        </View>
        <View className="items-center">
          <Text className="font-[Jakarta-ExtraBold] text-gray-500">ya da</Text>
          <View className="flex-row items-center gap-3 ">
            <Ionicons name="logo-google" size={30} />
            <Text className="font-[Jakarta-Bold] text-gray-700">
              Google ile davam et
            </Text>
          </View>
        </View>
        <View className="items-center">
          <Text className="text-gray-500">
            {isSignIn ? "Hesabiniz yoxdur?" : "Artiq hesabiniz var?"}{" "}
            <Text
              onPress={() =>
                router.push({
                  pathname: "/auth",
                  params: { type: isSignIn ? "sign-up" : "sign-in" },
                })
              }
              className="text-[#fb9401] font-[Jakarta-Bold]"
            >
              Daxil ol
            </Text>
          </Text>
        </View>
      </View>
    </SafeAreaView>
  );
}
