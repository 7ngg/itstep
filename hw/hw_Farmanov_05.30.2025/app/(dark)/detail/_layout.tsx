import { Stack } from "expo-router";
import { View } from "react-native";

const StackLayout = () => {
  return (
    <View style={{ flex: 1, backgroundColor: "#151A28" }}>
      <Stack
        screenOptions={{
          contentStyle: { backgroundColor: "#151A28" },
        }}
      >
        <Stack.Screen
          name="index"
          options={{
            headerShown: false,
          }}
        />
      </Stack>
    </View>
  );
};

export default StackLayout;
