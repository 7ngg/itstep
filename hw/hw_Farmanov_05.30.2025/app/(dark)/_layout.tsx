import { Stack } from "expo-router";
import { StyleSheet, Text, View } from "react-native";
import { BlurView } from "expo-blur";

const TabsLayout = () => {
  return (
    <View style={styles.container}>
      <Stack
        screenOptions={{
          headerShown: false,
        }}
      >
        <Stack.Screen name="(tabs)" />
      </Stack>
    </View>
  );
};

export default TabsLayout;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#0A0F1D",
    position: "relative",
  },
  
});
