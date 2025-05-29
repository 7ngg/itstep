import { Pressable, StyleSheet, Text, TextInput, View } from "react-native";
import { SafeAreaView } from "react-native-safe-area-context";
import { globalStyles } from "./global-styles";
import { useState } from "react";
import { useRouter } from "expo-router";
import AsyncStorage from "@react-native-async-storage/async-storage";

export default function Index() {
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");

  const router = useRouter();

  const handleSignIn = () => {
    fetch("http://192.168.100.3:8080/auth/sign-in", {
      method: "POST",
      body: JSON.stringify({ username, password }),
    }).then(async (res) => {
      const data = await res.json();

      if (!res.ok) {
        setError(data.error);
        return;
      }

      AsyncStorage.setItem("accessToken", data.accessToken);

      router.navigate("/account");
    });
  };

  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.form}>
        <Text style={styles.header}>Sign In</Text>
        <View
          style={{
            width: "100%",
            alignItems: "center",
            gap: 4,
          }}
        >
          <TextInput
            style={styles.TextInput}
            placeholder="Username"
            value={username}
            onChangeText={setUsername}
          />
          <TextInput
            style={styles.TextInput}
            placeholder="Password"
            value={password}
            onChangeText={setPassword}
          />
        </View>
        {error.length != 0 ? <Text style={{ color: "red" }}>{error}</Text> : ""}
        <Pressable style={styles.button} onPress={handleSignIn}>
          <Text>Sign In</Text>
        </Pressable>
        <Text>Don't have an account yet? Sign up</Text>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    alignItems: "center",
    justifyContent: "center",
    height: "100%",
    backgroundColor: globalStyles.background,
  },
  form: {
    padding: 4,
    height: "50%",
    width: "90%",
    alignItems: "center",
    gap: 12,
  },
  TextInput: {
    width: "90%",
    height: 40,
    paddingVertical: 4,
    paddingHorizontal: 16,
    backgroundColor: globalStyles.backgroundLighter,
    borderRadius: 10,
  },
  header: {
    fontSize: 48,
    fontWeight: 700,
    color: globalStyles.foreground,
  },
  button: {
    width: "90%",
    height: 40,
    alignItems: "center",
    justifyContent: "center",
    backgroundColor: globalStyles.accent,
    borderRadius: 10,
  },
});
